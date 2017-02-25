#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;

private slots:
	void on_actionOpenSpriteImage_triggered();
	void on_actionOpenSpriteJSON_triggered();
	void on_previousIndexButton_clicked();
	void on_nextIndexButton_clicked();
};

#endif // MAINWINDOW_H
