#pragma once
#include <QWidget>

namespace Ui {
  class UserWidget;
}

class UserWidget final
    : public QWidget
{
  Q_OBJECT
  Ui::UserWidget *ui;

public:
  explicit UserWidget(QWidget *parent = nullptr);
  ~UserWidget() override;

public slots:
  void add();
  void remove();
};
