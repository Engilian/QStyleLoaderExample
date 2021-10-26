#pragma once
#include <QPushButton>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ExampleMainWindow; }
QT_END_NAMESPACE

class ExampleMainWindow final
    : public QMainWindow
{
  Q_OBJECT
  const QString STYLE_PATH;

  const int ROW_COUNT;
  const int COLUMN_COUNT;
  const int COUNT;
  int       m_current;

  Ui::ExampleMainWindow *ui;
  QList<QPushButton*>   m_buttons;
public:
  ExampleMainWindow(QWidget *parent = nullptr);
  ~ExampleMainWindow();

public slots:
  void textChanged();

  // QObject interface
protected:
  void timerEvent(QTimerEvent *) override;
};
