import requests
from bs4 import BeautifulSoup
import re
import os
import shutil
import sys
import re
import subprocess
import glob
from getpass import getpass


# from src import myconfig
# from src import atcoder_autotest as acat

ROOT_DIR = os.path.abspath("./")

LOGIN_URL = "https://beta.atcoder.jp/login"
CONTSET_URL  = "https://atcoder.jp/contests/"

# USERNAME = myconfig.USERNAME
# PASSWORD = myconfig.PASSWORD

if __name__ == "__main__":
	# print(os.path.join(ROOT_DIR,"src/","myconfig.py"))

	# 初めて使うときはユーザー情報を取得する
	if not os.path.isfile(os.path.join(ROOT_DIR,"src/","myconfig.py")):
		file_name = "myconfig.py"
		path = os.path.join(ROOT_DIR,"src/",file_name)
		username=input("your username : ")
		password = getpass("your password : ")
		with open(path,mode='w') as f:
			f.write("USERNAME='{}'\n".format(username))
			f.write("PASSWORD='{}'\n".format(password))
	
	from src import atcoder_autotest as acat
	from src import myconfig
	USERNAME = myconfig.USERNAME
	PASSWORD = myconfig.PASSWORD	

	args = sys.argv

	# コンテストフォルダ等作成
	if args[1] == "make":
		contest_name = args[2]
		print(contest_name)
		acat.make_contest(ROOT_DIR,contest_name)
	elif args[1] == "test":
		contest_name = args[2]
		problem_name = args[3]

		task_url = CONTSET_URL+contest_name+"/tasks/"+problem_name

		# TODO: ファイル名からコンテスト名を取得できるようにする
		task_path = os.path.join(ROOT_DIR,contest_name,"test/",problem_name)
		if(glob.glob(task_path+"/*")==[]):
			acat.get_tests(task_path,task_url)
		acat.comp(ROOT_DIR,problem_name)
		acat.test(ROOT_DIR,contest_name,problem_name)
