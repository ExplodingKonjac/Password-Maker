import sys
import json
import random
import functools

from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *

from MainWindow import Ui_MainWindow

formula={"UL":["R","X","D","E","F","P","G","H","B","Q","Y","Z","I","C","V","W","A","L","J","K","S","T","U","M","N","O"],
		 "LL":["m","n","b","c","h","l","p","d","k","g","t","u","o","j","a","e","s","x","y","z","i","f","v","w","q","r"],
		 "NB":["7","1","9","4","6","3","8","2","5","0"],
		 "SB":["~","!","@","#","$","%","^","&","*","(",")","_","+","-","=","{","}","[","]","|",":",";","<",">",",",".","?","/"],
		 "order":["UL","LL","NB","SB"]}
_tr=functools.partial(QCoreApplication.translate,"MainWindow")

def resort(lst: list):
	res=[]
	while len(lst):
		idx=random.randint(0,len(lst)-1)
		res.append(lst[idx])
		lst.pop(idx)
	return res

def make_psw(web: str,check: dict,dfc: int):
	res=""
	i=0
	for i in formula["order"]:
		letters=formula[i]
		if check[i]==False:
			continue
		for j in range(min(len(web),dfc)):
			res+=letters[ord(web[j])%len(letters)]
	return res

class MainWindow(QMainWindow,Ui_MainWindow):
	def __init__(self,parent=None):
		super().__init__(parent)
		self.trans=QTranslator()
		self.setupUi(self)
		self.setFixedSize(800,600)
		self.setWindowIcon(QIcon("logo.png"))
		self.changeFormula.clicked.connect(self.changeMaker)
		self.makePassword.clicked.connect(self.outputPassword)
		self.zh_cn.triggered.connect(functools.partial(self.changeLang,"zh_cn"))
		self.en.triggered.connect(functools.partial(self.changeLang,"en"))

	def outputPassword(self):
		web=self.editWeb.text()
		psw=make_psw(web,{"UL":self.hasUL.isChecked()
						 ,"LL":self.hasLL.isChecked()
						 ,"NB":self.hasNumber.isChecked()
						 ,"SB":self.hasSymbol.isChecked()},self.chooseComplexity.value())
		self.showPassword.setText(psw)
	
	def changeMaker(self):
		reply=QMessageBox.warning(self,_tr("Change formula"),_tr("Are you sure?"),QMessageBox.Yes|QMessageBox.No)
		if(reply==QMessageBox.Yes):
			formula["order"]=resort(formula["order"])
			formula["UL"]=resort(formula["UL"])
			formula["LL"]=resort(formula["LL"])
			formula["NB"]=resort(formula["NB"])
			formula["SB"]=resort(formula["SB"])
			self.outputPassword()
	
	def closeEvent(self,QCloseEvent):
		reply=QMessageBox.warning(self,_tr("Quit"),_tr("Save changes before leaving?"),QMessageBox.Yes|QMessageBox.No|QMessageBox.Cancel)
		if reply==QMessageBox.Cancel:
			QCloseEvent.ignore()
		else:
			if reply==QMessageBox.Yes:
				f=open("save.json","w")
				json.dump(formula,f,indent=4)
			QCloseEvent.accept()

	def changeLang(self,lang):
		self.trans.load("translations/"+lang)
		_app=QApplication.instance()
		_app.installTranslator(self.trans)
		self.retranslateUi(self)


if __name__ == "__main__":
	try:
		f=open("save.json","r")
		formula=json.load(f)
	except FileNotFoundError:
		formula["order"]=resort(formula["order"])
		formula["UL"]=resort(formula["UL"])
		formula["LL"]=resort(formula["LL"])
		formula["NB"]=resort(formula["NB"])
		formula["SB"]=resort(formula["SB"])
	app=QApplication(sys.argv)
	window=MainWindow()
	window.show()
	sys.exit(app.exec_())