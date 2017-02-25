#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionOpenSpriteImage_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Select a sprite file"), "/home", "Image (*.png)");
	QImage *imageObject = new QImage();
	imageObject->load(fileName);

	QPixmap image = QPixmap::fromImage(*imageObject);

	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addPixmap(image);
	scene->setSceneRect(image.rect());
	ui->spriteGraphicsView->setScene(scene);
}

void MainWindow::on_actionOpenSpriteJSON_triggered()
{
	QStringList listForView;

	QString fileName = QFileDialog::getOpenFileName(this, tr("Select a sprite file"), "/home", "JSON (*.json *.txt)");

	QFile file(fileName);
	bool isFileOpened = file.open(QIODevice::ReadOnly);
	if (!isFileOpened) {
		// TODO: error
		return;
	}

	QByteArray fileContent = file.readAll();
	QJsonDocument jsonDocument = QJsonDocument::fromJson(fileContent);
	QJsonObject jsonObject = jsonDocument.object();

	QString imageIdentifier = jsonObject["image"].toString();
	listForView << imageIdentifier;

	QJsonArray cellArray = jsonObject["cell"].toArray();
	int cellWidth = cellArray[0].toInt(0);
	int cellHeight = cellArray[1].toInt(0);
	listForView << "Cell width: " + QString::number(cellWidth) + ", height: " + QString::number(cellHeight);

	QJsonArray marginArray = jsonObject["margin"].toArray();
	int topLeftMargin = marginArray[0].toInt(0);
	int bottomRightMargin = marginArray[1].toInt(0);
	listForView << "Top/left margin: " + QString::number(topLeftMargin) + ", bottom/right margin: " + QString::number(bottomRightMargin);

	QJsonArray spaceArray = jsonObject["space"].toArray();
	int horizontalSpace = spaceArray[0].toInt(0);
	int verticalSpace = spaceArray[1].toInt(0);
	listForView << "Horizontal space: " + QString::number(horizontalSpace) + ", vertical space: " + QString::number(verticalSpace);

	QJsonArray sizeArray = jsonObject["size"].toArray();
	int sizeWidth = sizeArray[0].toInt(cellWidth);
	int sizeHeight = sizeArray[1].toInt(cellHeight);
	listForView << "Size width: " + QString::number(sizeWidth) + ", height: " + QString::number(sizeHeight);

	QStandardItemModel *model = new QStandardItemModel;
	int i = 0;
	for (QString string : listForView) {
		QStandardItem *item = new QStandardItem(string);
		model->setItem(i, item);
		i++;
	}

	ui->indexListView->setModel(model);
}

void MainWindow::on_previousIndexButton_clicked()
{
	std::cout << "p" << std::endl;
}

void MainWindow::on_nextIndexButton_clicked()
{
	std::cout << "n" << std::endl;
}
