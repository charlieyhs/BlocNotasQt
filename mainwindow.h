#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_Como_triggered();

    void on_actionQuitar_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionAcerca_de_Qt_triggered();

    void on_actionColor_triggered();

    void on_actionTipo_triggered();

    void on_actionColorFondo_triggered();

    void on_actionImprimir_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
