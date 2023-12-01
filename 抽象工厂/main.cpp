#include <QtCore/QCoreApplication>

#include <iostream>
#include <QString>

/*
在这个示例中，我们定义了两个抽象产品：AbstractButton 和 AbstractTextBox。然后，我们为深色和浅色主题分别定义了这些抽象产品的具体实现。

接下来，我们定义了一个抽象工厂 AbstractThemeFactory，它可以创建这两种产品，然后我们为深色和浅色主题分别定义了具体工厂。

在 main() 函数中，我们演示了如何使用这些工厂来创建并使用不同主题的按钮和文本框。

这样，如果以后我们想要添加更多的主题或组件，我们只需要扩展相应的工厂和产品即可，而不需要修改现有代码。这就是使用抽象工厂模式的好处。

*/
// 抽象产品：Button
class AbstractButton {
public:
    virtual QString color() = 0;
};

// 抽象产品：TextBox
class AbstractTextBox {
public:
    virtual QString textColor() = 0;
};

// 具体产品：DarkButton
class DarkButton : public AbstractButton {
public:
    QString color() {
        return "Dark";
    }
};

// 具体产品：LightButton
class LightButton : public AbstractButton {
public:
    QString color() {
        return "Light";
    }
};

// 具体产品：DarkTextBox
class DarkTextBox : public AbstractTextBox {
public:
    QString textColor() {
        return "White";
    }
};

// 具体产品：LightTextBox
class LightTextBox : public AbstractTextBox {
public:
    QString textColor() {
        return "Black";
    }
};

// 抽象工厂
class AbstractThemeFactory {
public:
    virtual AbstractButton* createButton() = 0;
    virtual AbstractTextBox* createTextBox() = 0;
};

// 具体工厂：DarkThemeFactory
class DarkThemeFactory : public AbstractThemeFactory {
public:
    AbstractButton* createButton() {
        return new DarkButton();
    }
    AbstractTextBox* createTextBox() {
        return new DarkTextBox();
    }
};

// 具体工厂：LightThemeFactory
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

    // 清理资源
    delete button;
    delete textBox;
    delete factory;

    // 使用浅色主题工厂
    factory = new LightThemeFactory();
    button = factory->createButton();
    textBox = factory->createTextBox();

    std::cout << "Button color: " << button->color().toStdString() << ", TextBox textColor: " << textBox->textColor().toStdString() << std::endl;

    // 清理资源
    delete button;
    delete textBox;
    delete factory;


    return a.exec();
}
