#ifndef lineedits_H
#define lineedits_H

#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

class QComboBox;
class QLineEdit;


class lineedits : public QWidget
{
    Q_OBJECT
public:
    lineedits();
    virtual ~lineedits();

public slots:
    void echoChanged(int);
    void validatorChanged(int);
    void alignmentChanged(int);
    void inputMaskChanged(int);
    void accessChanged(int);

private:
    QLineEdit *echoLineEdit;
    QLineEdit *validatorLineEdit;
    QLineEdit *alignmentLineEdit;
    QLineEdit *inputMaskLineEdit;
    QLineEdit *accessLineEdit;


};

#endif // lineedits_H
