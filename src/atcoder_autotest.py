import requests
from bs4 import BeautifulSoup
import re
import os
import shutil
import sys
import re
import subprocess
import glob

import pdb

# from . import myconfig

LOGIN_URL = "https://beta.atcoder.jp/login"
CONTSET_URL_HEAD = "https://atcoder.jp/contests/"

# def make_url(contest_name,problem_name):
# 	"""
# 	問題urlを作成
# 	"""
# 	return CONTSET_URL_HEAD+contest_name+ "/tasks/"+contest_name+"_"+problem_name

def make_dir(DIR,contest_name,problem):
	"""
	問題ディレクトリを作成
	(テストがおいてあるディレクトリのこと)
	"""
	return os.path.join(DIR,contest_name,"test/",problem)


def getTests(dir,url):
	"""
	url先のページからテストを取得する.
	テストごとにテストの入力/出力ファイルを作成する

	Parameter
	------
	url : str,問題ページのurl
	dir : str, path
	"""

	# session = requests.session()

	# r = session.get(LOGIN_URL)
	# s = BeautifulSoup(r.text,'html.parser')
	# csrf_token = s.find(attrs={'name': 'csrf_token'}).get('value')

	# login_info = {
	# 	"csrf_token": csrf_token,
	# 	"username": myconfig.USERNAME,
	# 	"password": myconfig.PASSWORD
	# }

	# result = session.post(LOGIN_URL, data=login_info)
	# result.raise_for_status()
	# if result.status_code==200:
	# 	print("log in!")
	# else:
	# 	print("failed...")
	

	page = requests.get(url)
	soup = BeautifulSoup(page.content, 'html.parser')
	
	#TODO: divの場合とsectionの場合がある?古いものはdivぽい
	for div in soup.find_all('div'):
		h3s = div.find_all("h3")
		for h3 in h3s:
			# print(div)
			if "入力例" in h3.text:
				s = h3.text
				# print(h3.text)
				n = re.search("\d(?![>])",s).group()
				x = div.find('pre').get_text()
				x = str(x).lstrip()
				file_name = "input_"+str(n)+".txt"
				path = os.path.join(dir,file_name)
				with open(path,mode='w') as f:
					f.write(x)
			if "出力例" in h3.text:
				s = h3.text
				n = re.search("\d(?![>])",s).group()
				x = div.find('pre').get_text()
				x = str(x).lstrip()
				# '\n'.join(filter(lambda a: a.strip(), x.split('\n')))
				# x = re.sub("^[\n]","",x,1)
				# x = x.rstrip('\r\n')
				file_name = "output_"+str(n)+".txt"
				path = os.path.join(dir,file_name)

				x = x.replace('\r','')

				with open(path,mode='w') as f:
					f.write(x)
	for sec in soup.find_all('section'):
		h3s = sec.find_all("h3")
		# import pdb; pdb.set_trace()
		for h3 in h3s:
			if "入力例" in h3.text:
				s = h3.text
				n = re.search("\d(?![>])",s).group()
				x = sec.find('pre').get_text()
				x = str(x).lstrip()
				file_name = "input_"+str(n)+".txt"
				path = os.path.join(dir,file_name)
				with open(path,mode='w') as f:
					f.write(x)
			if "出力例" in h3.text:
				s = h3.text
				n = re.search("\d(?![>])",s).group()
				x = sec.find('pre').get_text()
				x = str(x).lstrip()
				file_name = "output_"+str(n)+".txt"
				path = os.path.join(dir,file_name)

				x = x.replace('\r','')

				with open(path,mode='w') as f:
					f.write(x)

def makeContest(DIR,contest_name):
	"""
	コンテスト開始前に動かすことを想定
	コンテストのディレクトリを作成
		contest-- src
			|- test
	問題数を指定してその数だけsrc直下にcppファイルを作成

	Parameters
	---------
	contest_name : str, abc122とかコンテストの名前
	DIR : str, path
	"""
	path 		= os.path.join(DIR,contest_name)
	src_path 	= os.path.join(path,"src")
	test_path 	= os.path.join(path,"test")

	os.makedirs(src_path,exist_ok=True)
	os.makedirs(test_path,exist_ok=True)

	problems = get_problems(contest_name)
	num = len(problems)

	for name in problems:
		print(name)

	for i in range(num):
		problem_path = os.path.join(test_path,problems[i])
		os.makedirs(problem_path,exist_ok=True)

	template = os.path.join(DIR,"template.cpp")
	for i in range(num):
		file_name = problems[i]+".cpp"
		file_path = os.path.join(path,"src",file_name)
		if not os.path.isfile(file_path):
			shutil.copy(template,file_path)

def get_problems(contest_name):
	"""
	コンテストurlからコンテストの問題のリンクを取得する
	abc001_1とか


	"""
	url  = CONTSET_URL_HEAD + contest_name + "/tasks/"
	page = requests.get(url)
	soup = BeautifulSoup(page.content, 'html.parser')

	problem_names = []

	# 企業コン用
	# contests/diverta2019-2/tasks/diverta2019_2_a　になってる時があるので
	contest_name_to_underscore = contest_name.replace('-','_')
	for aa in soup.find_all("a"):
		link = aa.get("href")
		if(re.match("/contests/"+contest_name+"/tasks/"+contest_name_to_underscore,str(link)) is None):
			continue
		problem_name = link.split(sep='/')[-1]
		problem_names.append(problem_name)

	return sorted(list(set(problem_names)))

	

def comp(DIR,problem_name):
	"""
	cppをコンパイルする

	Parameter
	---------
	problem_name : str
	"""
	# TODO: contest_nameバグる
	# ex. diverta-2
	contest_name,problem_number = problem_name.split(sep='_')[0], problem_name.split(sep='_')[-1]
	contest_dir = os.path.join(DIR,contest_name)
	src_dir = os.path.join(contest_dir,"src/")
	problem_path = os.path.join(src_dir,problem_name)
	subprocess.run(["g++",problem_path+".cpp","-o",os.path.join(src_dir,problem_name)])

def test(DIR,contest_name,problem_name):
	"""
	テストをする
	入出力を表示する
	正解は正解したと知らせるだけにする
	間違えた問題だけ入出力を表示する

	制限時間以上かかったら強制終了するようにしたい

	Parameter
	--------
	problem_name : str
	DIR : str, path
	"""
	# contest_name,problem_number = problem_name.split(sep='_')
	contest_dir = os.path.join(DIR,contest_name)
	src_dir = os.path.join(contest_dir,"src/")
	test_dir = os.path.join(contest_dir,"test/",problem_name)
	input_files = sorted([file_name for file_name in os.listdir(test_dir) if re.match("^input",file_name)])

	program = os.path.join(contest_dir,"src/",problem_name)

	for input_file in input_files:
		num = re.search("\d",input_file).group()
		output_file = "output_"+str(num)+".txt"

		input = subprocess.run(["cat",input_file],stdout=subprocess.PIPE,cwd=test_dir)
		output = subprocess.run(["cat",output_file],stdout=subprocess.PIPE,cwd=test_dir)
		answer = subprocess.run(["./"+problem_name],input=input.stdout,stdout=subprocess.PIPE,cwd=src_dir)
		path = os.path.join(test_dir,"answer_"+num+".txt")
		with open(path,mode='w') as f:
			f.write(answer.stdout.decode("utf8"))

		if(answer.stderr):
			print("----sample {} RE!!!----".format(num))
			print(answer.stderr)
		elif(output.stdout!=answer.stdout):
			print("----sample {} WA!!!----".format(num))
			print("----input----")
			print(input.stdout.decode("utf8"))

			print("----Expected output----")
			print(output.stdout.decode("utf8"))

			print("----Your answer----")
			print(answer.stdout.decode("utf8"))
		else:
			print("----sample {} passed!!!----".format(num))
		print("\n")

if __name__ == "__main__":
	# args = sys.argv
	# # for arg in args:
	# # 	print(arg)

	# if args[1] == "make":
	# 	contest_name = args[2]
	# 	contest_round = args[3]
	# 	number_of_problems = int(args[4])
	# 	contest_name = "{}{:03d}".format(contest_name,int(contest_round))
	# 	print(contest_name)
	# 	# contest_url = CONTSET_URL_HEAD+contest_name+"/"
	# 	makeContest(contest_name,number_of_problems)

	# elif args[1] == "test":
	# 	contest_name = args[2]
	# 	contest_round = args[3]
	# 	problem = args[4]

	# 	contest_name = "{}{:03d}".format(contest_name,int(contest_round))
	# 	problem_name = contest_name+"_"+str(problem)
	# 	task_url = CONTSET_URL_HEAD+contest_name+"/tasks/"+problem_name
	# 	task_path = os.path.join(ROOT_DIR,contest_name,"test/",problem)
	# 	if(glob.glob(task_path)==[]):
	# 		getTests(task_url)
	# 	test(problem_name)
	# elif args[1] == "comp":
	# 	contest_name = args[2]
	# 	contest_round = args[3]
	# 	problem = args[4]

	# 	contest_name = "{}{:03d}".format(contest_name,int(contest_round))
	# 	problem_name = contest_name+"_"+str(problem)
	# 	comp(problem_name)

	test_name = "abc010"
	print(get_problems(test_name))