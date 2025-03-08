#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void markTaskAsDone();
    void editTask();
    void removeTask();
    void removeAllTasks();

private:
    Ui::MainWindow *ui;

    // Declare the save and load functions here
    void saveTasks();
    void loadTasks();
};

#endif // MAINWINDOW_H
