#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {

class MainWindow;

} // !Ui

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QScopedPointer<Ui::MainWindow> ui_;

private slots:
	void on_actionOpenSpriteImage_triggered();
	void on_actionOpenSpriteJSON_triggered();
	void on_previousIndexButton_clicked();
	void on_nextIndexButton_clicked();
};

#endif // MAINWINDOW_H
