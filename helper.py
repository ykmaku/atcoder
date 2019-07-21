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
CONTSET_URL = url = "https://atcoder.jp/contests/"

# USERNAME = myconfig.USERNAME
# PASSWORD = myconfig.PASSWORD

if __name__ == "__main__":
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

	if args[1] == "make":
		contest_name = args[2]
		contest_round = args[3]
		number_of_problems = int(args[4])
		contest_name = "{}{:03d}".format(contest_name,int(contest_round))
		print(contest_name)
		acat.make_contest(ROOT_DIR,contest_name,number_of_problems)
	elif args[1] == "test":
		contest_name = args[2]
		contest_round = args[3]
		problem = args[4]

		contest_name = "{}{:03d}".format(contest_name,int(contest_round))
		problem_name = contest_name+"_"+str(problem)
		task_url = acat.make_url(contest_name,problem)
		task_path = acat.make_dir(ROOT_DIR,contest_name,problem)
		if(glob.glob(task_path+"/*")==[]):
			# acat.login(USERNAME,PASSWORD)
			acat.get_tests(task_path,task_url)
		acat.comp(ROOT_DIR,problem_name)
		acat.test(ROOT_DIR,problem_name)
