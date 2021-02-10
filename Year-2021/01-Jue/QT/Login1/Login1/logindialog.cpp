#include "logindialog.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#pragma execution_character_set("utf-8")

LoginDialog::LoginDialog(QWidget *parent) :QDialog(parent)
{
    usrLabel = new QLabel(this);
	usrLabel->move(70, 80);
	usrLabel->setText("用户名：");
	usrLineEdit = new QLineEdit(this);
	usrLineEdit->move(140, 80);
	usrLineEdit->setPlaceholderText("请输入用户名:");

	pwdLabel = new QLabel(this);
	pwdLabel->move(70, 130);
	pwdLabel->setText("密码:");
	pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
	pwdLineEdit->setPlaceholderText("请输入密码:");

	loginBtn = new QPushButton(this);
	loginBtn->move(50, 200);
	loginBtn->setText("登录");
	editBtn = new QPushButton(this);
	editBtn->move(210, 200);
	editBtn->setText("退出");

	connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(login()));
	connect(editBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::login()
{
	if (usrLineEdit->text().trimmed()=="yonghuming"&&pwdLineEdit->text().trimmed()=="mima")
	{
		accept();
	}
	else
	{
		QMessageBox::warning(this, "警告！", "用户名和密码错误！", QMessageBox::Yes);
		usrLineEdit->clear();
		pwdLineEdit->clear();
		usrLineEdit->setFocus();
	}
}
