#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbrir_triggered(){
    QFile arch;
    QString nombreArch;
    QTextStream io;

    nombreArch = QFileDialog::getOpenFileName(this, "Abrir");
    if(nombreArch.isEmpty()){
        return;
    }
    arch.setFileName(nombreArch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!arch.isOpen()){
        QMessageBox::critical(this,"Error ",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->textEdit->setText(io.readAll());
    arch.close();
}

void MainWindow::on_actionGuardar_Como_triggered(){
    QFile arch;
    QTextStream io;
    QString nombreArch;

    nombreArch = QFileDialog::getSaveFileName(this, "Guardar");
    if(nombreArch.isEmpty()){
        return;
    }
    arch.setFileName(nombreArch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error ",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    io << ui->textEdit->toPlainText();
    arch.flush();
    arch.close();

}

void MainWindow::on_actionQuitar_triggered(){
    close();
}

void MainWindow::on_actionCopiar_triggered(){
    ui->textEdit->copy();
}

void MainWindow::on_actionCortar_triggered(){
    ui->textEdit->cut();
}

void MainWindow::on_actionPegar_triggered(){
    ui->textEdit->paste();
}

void MainWindow::on_actionAcerca_de_triggered(){
    QString txt;
    txt = "Autor: Carlos Yecid\n";
    txt += "Fecha: 30/12/2021\n";
    txt += "Software: (C)Notepad(R)\n";

    QMessageBox::about(this,"Notepad",txt);
}

void MainWindow::on_actionAcerca_de_Qt_triggered(){
    QMessageBox::aboutQt(this, "Qt");
}

void MainWindow::on_actionColor_triggered(){
    QColor color;
    color = QColorDialog::getColor(Qt::white, this);
    ui->textEdit->setTextColor(color);
}

void MainWindow::on_actionTipo_triggered(){
    bool ok;
    QFont fuente;
    fuente = QFontDialog::getFont(&ok, this);
    if(!ok)
        return;
    ui->textEdit->setFontPointSize(fuente.pointSizeF());
    ui->textEdit->setFontFamily(fuente.family());
}

void MainWindow::on_actionColorFondo_triggered(){
    QColor color;
    color = QColorDialog::getColor(Qt::white, this);
    ui->textEdit->setPalette(QPalette(color));
}

void MainWindow::on_actionImprimir_triggered(){
    QPrinter *impresora;
    QPrintDialog pd(this);
    if(pd.exec() == QDialog::Rejected) return;
    impresora = pd.printer();

    ui->textEdit->print(impresora);
}
