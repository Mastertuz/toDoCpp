#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QStyledItemDelegate>
#include <QPainter>

// Custom delegate to style list items
class CustomItemDelegate : public QStyledItemDelegate {
public:
    explicit CustomItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Customize appearance based on checked state
        if (opt.checkState == Qt::Checked) {
            opt.font.setStrikeOut(true); // Add strikethrough
            opt.palette.setColor(QPalette::Text, QColor(128, 128, 128)); // Change text color to gray
        } else {
            opt.font.setStrikeOut(false); // Remove strikethrough
            opt.palette.setColor(QPalette::Text, QColor("#9E78CF")); // Default text color
        }

        // Draw the item with custom styles
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up the UI
    setWindowTitle("To-Do List App");
    ui->taskInput->setPlaceholderText("Add a new task");

    // Set custom delegate for the QListWidget
    ui->taskList->setItemDelegate(new CustomItemDelegate(this));

    // Connect buttons to slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->doneButton, &QPushButton::clicked, this, &MainWindow::markTaskAsDone);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::editTask);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);
    connect(ui->removeAllButton, &QPushButton::clicked, this, &MainWindow::removeAllTasks);

    // Apply styles
    setStyleSheet(
        // Main window background
        "QMainWindow {"
        "   background: #0D0714;"
        "   color: #FFFFFF;"
        "}"

        // QLineEdit (task input)
        "QLineEdit {"
        "   background-color: transparent;"
        "   color: #FFFFFF;"
        "   border: 1px solid #9E78CF;"
        "   border-radius: 10px;"
        "   font-size: 14px;"
        "   padding: 8px;"
        "}"

        // QPushButton (add, done, edit, remove, remove all buttons)
        "QPushButton {"
        "   background-color: #9E78CF;"
        "   color: #FFFFFF;"
        "   border: 1px solid #666666;"
        "   border-radius: 8px;"
        "   padding: 8px 16px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3E1671;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #270750;"
        "}"

        // QListWidget (task list)
        "QListWidget {"
        "   background-color: #1D1825;"
        "   color: #FFFFFF;"
        "   border: 1px solid #555555;"
        "   border-radius: 8px;"
        "   padding: 8px;"
        "   font-size: 14px;"
        "}"
        "QListWidget::item {"
        "   background-color: #15101C;"
        "   border-radius: 8px;"
        "   padding: 12px;"
        "   margin: 4px;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #15101C;"
        "   border: none;"
        "   outline: none;"
        "}"
        "QListView{"
        "outline:none;"
        "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QString task = ui->taskInput->text().trimmed();
    if (!task.isEmpty()) {
        QListWidgetItem *item = new QListWidgetItem(task, ui->taskList);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->taskInput->clear();
    }
}

void MainWindow::markTaskAsDone()
{
    QListWidgetItem *item = ui->taskList->currentItem();
    if (item) {
        if (item->checkState() == Qt::Unchecked) {
            item->setCheckState(Qt::Checked);
        } else {
            item->setCheckState(Qt::Unchecked);
        }
    }
}

void MainWindow::editTask()
{
    QListWidgetItem *item = ui->taskList->currentItem();
    if (item) {
        bool ok;
        QString newText = QInputDialog::getText(this, tr("Edit Task"), tr("Edit Task:"), QLineEdit::Normal, item->text(), &ok);
        if (ok && !newText.isEmpty()) {
            item->setText(newText);
        }
    }
}

void MainWindow::removeTask()
{
    QListWidgetItem *item = ui->taskList->currentItem();
    if (item) {
        delete ui->taskList->takeItem(ui->taskList->row(item));
    }
}

void MainWindow::removeAllTasks()
{
    if (QMessageBox::question(this, tr("Remove All Tasks"), tr("Are you sure you want to remove all tasks?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        ui->taskList->clear();
    }
}
