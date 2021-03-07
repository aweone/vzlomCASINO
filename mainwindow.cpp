#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <cstdlib>
#include "QString"
#include "stdlib.h"
#include "phonon4qt5/phonon/MediaObject"
#include "phonon4qt5/phonon/AudioOutput"
#include "phonon4qt5/phonon/MediaSource"
#include "QPixmap"

int clicks = 0;
const int tRubles = rand()%99999999+10000000;
bool soundOn = false;
//const int tRubles = 7;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    QString inf = "Казино взломано на 0% \n"
        "0 руб. из " + QString::number(tRubles) + " руб. \n Продолжить?";
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText(inf);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_No_clicked()
{
    QMessageBox::information(0,"","Да");
}

void MainWindow::on_Yes_clicked()
{
    clicks++;
    QString cRubles = QString::number((tRubles / 100)*clicks);
    QString Rubles = QString::number(tRubles);
    QString percents = QString::number(clicks);


    if ((tRubles - ((tRubles / 100)*clicks)) < (tRubles / 100)) {
        QString cRubles = QString::number(tRubles);
        QString inf = "КАЗИНО взломано. Деньги пошли\n на оплату fisting.";
        ui->label->setText(inf);
        QMessageBox::information(0,"","Казино взломано!");
        exit(0);
    }

    if (clicks > 75) {
        QString inf = "Bondage gay website взломано на " + percents + "% \n Выкачено "
            + cRubles + " bucks из " + Rubles + "\n bucks \n Продолжить fisting ass?";


        if (!soundOn) {

            Phonon::MediaObject *player = Phonon::createPlayer(
                        Phonon::MusicCategory,
                        Phonon::MediaSource(":/audio/sound.wav")
            );
            player->play();

            QPixmap pix(":/images/gorislav.png");

            ui->labelImage->setPixmap(pix);
            ui->label->setStyleSheet("color: rgb(255, 255, 255); font-size: 1; font: bold");
            //ui->label->setStyleSheet("font: bold");
            soundOn = true;
        }
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setText(inf);
    }

    else {
        QString inf = "Казино взломано на " + percents + "% \n"
            + cRubles + " руб. из " + Rubles + " руб. \n Продолжить?";

        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setText(inf);
    }
}
