#include <QtCore/QCoreApplication>

#include <iostream>
#include <QString>

/*
�����ʾ���У����Ƕ��������������Ʒ��AbstractButton �� AbstractTextBox��Ȼ������Ϊ��ɫ��ǳɫ����ֱ�������Щ�����Ʒ�ľ���ʵ�֡�

�����������Ƕ�����һ�����󹤳� AbstractThemeFactory�������Դ��������ֲ�Ʒ��Ȼ������Ϊ��ɫ��ǳɫ����ֱ����˾��幤����

�� main() �����У�������ʾ�����ʹ����Щ������������ʹ�ò�ͬ����İ�ť���ı���

����������Ժ�������Ҫ��Ӹ������������������ֻ��Ҫ��չ��Ӧ�Ĺ����Ͳ�Ʒ���ɣ�������Ҫ�޸����д��롣�����ʹ�ó��󹤳�ģʽ�ĺô���

*/
// �����Ʒ��Button
class AbstractButton {
public:
    virtual QString color() = 0;
};

// �����Ʒ��TextBox
class AbstractTextBox {
public:
    virtual QString textColor() = 0;
};

// �����Ʒ��DarkButton
class DarkButton : public AbstractButton {
public:
    QString color() {
        return "Dark";
    }
};

// �����Ʒ��LightButton
class LightButton : public AbstractButton {
public:
    QString color() {
        return "Light";
    }
};

// �����Ʒ��DarkTextBox
class DarkTextBox : public AbstractTextBox {
public:
    QString textColor() {
        return "White";
    }
};

// �����Ʒ��LightTextBox
class LightTextBox : public AbstractTextBox {
public:
    QString textColor() {
        return "Black";
    }
};

// ���󹤳�
class AbstractThemeFactory {
public:
    virtual AbstractButton* createButton() = 0;
    virtual AbstractTextBox* createTextBox() = 0;
};

// ���幤����DarkThemeFactory
class DarkThemeFactory : public AbstractThemeFactory {
public:
    AbstractButton* createButton() {
        return new DarkButton();
    }
    AbstractTextBox* createTextBox() {
        return new DarkTextBox();
    }
};

// ���幤����LightThemeFactory
class LightThemeFactory : public AbstractThemeFactory {
public:
    AbstractButton* createButton() {
        return new LightButton();
    }
    AbstractTextBox* createTextBox() {
        return new LightTextBox();
    }
};



int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    AbstractThemeFactory* factory = new DarkThemeFactory();
    AbstractButton* button = factory->createButton();
    AbstractTextBox* textBox = factory->createTextBox();

    std::cout << "Button color: " << button->color().toStdString() << ", TextBox textColor: " << textBox->textColor().toStdString() << std::endl;

    // ������Դ
    delete button;
    delete textBox;
    delete factory;

    // ʹ��ǳɫ���⹤��
    factory = new LightThemeFactory();
    button = factory->createButton();
    textBox = factory->createTextBox();

    std::cout << "Button color: " << button->color().toStdString() << ", TextBox textColor: " << textBox->textColor().toStdString() << std::endl;

    // ������Դ
    delete button;
    delete textBox;
    delete factory;


    return a.exec();
}
