#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QInputDialog>
#include <QString>

double balance = 0.0;

void updateLabel(QLabel* label) {
    label->setText(QString("Current Balance: €%1").arg(QString::number(balance, 'f', 2)));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Simple Banking App");

    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *balanceLabel = new QLabel();
    updateLabel(balanceLabel);
    layout->addWidget(balanceLabel);

    QPushButton *depositBtn = new QPushButton("Deposit Money");
    QPushButton *withdrawBtn = new QPushButton("Withdraw Money");
    QPushButton *exitBtn = new QPushButton("Exit");

    layout->addWidget(depositBtn);
    layout->addWidget(withdrawBtn);
    layout->addWidget(exitBtn);

    QObject::connect(depositBtn, &QPushButton::clicked, [&]() {
        bool ok;
        double amount = QInputDialog::getDouble(&window, "Deposit", "Enter amount to deposit:", 0, 0, 1e9, 2, &ok);
        if (ok) {
            balance += amount;
            updateLabel(balanceLabel);
        }
    });

    QObject::connect(withdrawBtn, &QPushButton::clicked, [&]() {
        bool ok;
        double amount = QInputDialog::getDouble(&window, "Withdraw", "Enter amount to withdraw:", 0, 0, 1e9, 2, &ok);
        if (ok) {
            if (amount > balance) {
                balanceLabel->setText("Insufficient funds!");
            } else {
                balance -= amount;
                updateLabel(balanceLabel);
            }
        }
    });

    QObject::connect(exitBtn, &QPushButton::clicked, [&]() {
        app.quit();
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
