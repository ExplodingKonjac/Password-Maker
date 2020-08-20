#include <bits/stdc++.h>
#include <QtWidgets/QStyleFactory>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QInputDialog>
#include <QtGui/QFontDatabase>
#include <QtGui/QtEvents>
#include <QtGui/QClipboard>
#include "classes/mainwindow.h"
#include "classes/settings.h"

QApplication *app;
AppSettings setting;

class MainWindow: public QMainWindow,public Ui_MainWindow
{
 private:
	std::list<QWidget*> widgets;
	void setSuitableFont()
	{
		QFont font;
		for(auto &w: widgets)
		{
			font=w->font();
			font.setPixelSize(w->height()*0.5);
			font.setFamily(setting.app_font);
			w->setFont(font);
		}
	}
 public:
	MainWindow(QWidget *parent=nullptr): QMainWindow(parent)
	{
		setupUi(this);
		setWindowIcon(QIcon(QPixmap("./logo.png")));
		has_ll->setChecked(setting.ll_chked);
		has_ul->setChecked(setting.ul_chked);
		has_nb->setChecked(setting.nb_chked);
		has_sb->setChecked(setting.sb_chked);
		complexity->setValue(setting.psw_level);
		widgets.push_back(label1),widgets.push_back(label2);
		widgets.push_back(has_ul),widgets.push_back(has_ll);
		widgets.push_back(has_nb),widgets.push_back(has_sb);
		widgets.push_back(input_web),widgets.push_back(show_psw);
		widgets.push_back(complexity);
		widgets.push_back(change_formula);
		widgets.push_back(make_psw),widgets.push_back(copy_psw);
		setSuitableFont();
		connect(make_psw,&QPushButton::clicked,this,&makePassword);
		connect(copy_psw,&QPushButton::clicked,this,&copyPassword);
		connect(change_formula,&QPushButton::clicked,this,&changeFormula);
		connect(import_formula,&QAction::triggered,this,&importFormula);
		connect(save_formula,&QAction::triggered,this,&saveFormula);
		connect(set_font,&QAction::triggered,this,&changeFont);
		connect(set_style,&QAction::triggered,this,&changeStyle);
	}
	void makePassword()
	{
		int level=has_ll->isChecked()+
				  has_ul->isChecked()+
				  has_nb->isChecked()+
				  has_sb->isChecked();
		if(!level)	return;
		union{ int _int;char _str[4]; } hash_res;
		std::string res,sub;
		std::hash<std::string> hash;
		hash_res._int=hash(input_web->text().toStdString());
		for(int i=1;i<=complexity->value()*4/level;i++)
		{
			sub.clear();
			hash_res._int=hash(hash_res._str);
			if(has_ll->isChecked())
				sub+=setting.llAtPos(std::abs((hash_res._int>>0)&255)%26);
			if(has_ul->isChecked())
				sub+=setting.ulAtPos(std::abs((hash_res._int>>8)&255)%26);
			if(has_nb->isChecked())
				sub+=setting.nbAtPos(std::abs((hash_res._int>>16)&255)%10);
			if(has_sb->isChecked())
				sub+=setting.sbAtPos(std::abs((hash_res._int>>24)&255)%31);
			std::shuffle(sub.begin(),sub.end(),setting.reorderFunc(hash_res._int));
			res+=sub;
		}
		show_psw->setText(res.c_str());
		QMessageBox::information(this,
								 "Tips","Password made successfully.",
								 QMessageBox::Ok);
	}
	void copyPassword()
	{
		QClipboard *cb=QApplication::clipboard();
		cb->setText(show_psw->text());
	}
	void changeFormula()
	{
		int res=QMessageBox::warning(this,
									 "Change Formula","Are you sure?",
									 QMessageBox::Yes|QMessageBox::No);
		if(res==QMessageBox::Yes)
		{
			setting.randSetting();
			makePassword();
		}
	}
	void importFormula()
	{
		QString file_name=QFileDialog::getOpenFileName(this,
													   "Import formula",
													   "..",
													   "Setting files (*.stg)");
		if(!file_name.isEmpty())
		{
			setting.load(file_name.toStdString());
			QMessageBox::information(this,
									 "Tips","Formula imported successfully.",
									 QMessageBox::Ok);
		}
	}
	void saveFormula()
	{
		QString file_name=QFileDialog::getSaveFileName(this,
													   "Save formula",
													   "..",
													   "Setting files (*.stg)");
		if(!file_name.isEmpty())
		{
			setting.save(file_name.toStdString());
			QMessageBox::information(this,
									 "Tips","Formula saved successfully",
									 QMessageBox::Ok);
		}
	}
	void changeFont()
	{
		bool ok;
		auto res=QInputDialog::getItem(this,
									   "Select font","Choose a font used in this app:",
									   QFontDatabase().families(),
									   0,false,&ok);
		if(ok)
		{
			app->setFont(QFont(res,9));
			memcpy(setting.app_font,res.toStdString().c_str(),20);
			setSuitableFont();
			QMessageBox::information(this,
									 "Tips","Font changed successfully.",
									 QMessageBox::Ok);
		}
	}
	void changeStyle()
	{
		bool ok;
		auto res=QInputDialog::getItem(this,
									   "Select style","Choose a style used in this app:",
									   QStyleFactory::keys(),
									   0,false,&ok);
		if(ok)
		{
			app->setStyle(QStyleFactory::create(res));
			memcpy(setting.app_style,res.toStdString().c_str(),20);
			QMessageBox::information(this,
									 "Tips","Style changed successfully.",
									 QMessageBox::Ok);
		}
	}
	void resizeEvent(QResizeEvent *event)
	{
		setSuitableFont();
	}
	void closeEvent(QCloseEvent *event)
	{
		int res=QMessageBox::warning(this,
									 "Quit","Do you want to save your changes?",
									 QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
		if(res==QMessageBox::Cancel)
			event->ignore();
		else
		{
			if(res==QMessageBox::Yes)
			{
				setting.ll_chked=has_ll->isChecked();
				setting.ul_chked=has_ul->isChecked();
				setting.nb_chked=has_nb->isChecked();
				setting.sb_chked=has_sb->isChecked();
				setting.psw_level=complexity->value();
				setting.save("./saves/setting.stg");
			}
			event->accept();
		}
	}
};

int main(int argc, char *argv[])
{
	app=new QApplication(argc,argv);
	MainWindow window;
	app->setStyle(QStyleFactory::create(setting.app_style));
	app->setFont(QFont(setting.app_font,9));
	window.show();
	return app->exec();
}
