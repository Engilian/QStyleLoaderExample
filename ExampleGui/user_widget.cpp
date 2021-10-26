#include "user_widget.h"
#include "ui_user_widget.h"

#include <QTime>
#include <QMessageBox>
#include <QInputDialog>

UserWidget::UserWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::UserWidget)
{
  ui->setupUi(this);
  connect( ui->add,     &QPushButton::clicked,
           this,        &UserWidget::add );
  connect( ui->remove,  &QPushButton::clicked,
           this,        &UserWidget::remove );
}

UserWidget::~UserWidget()
{
  delete ui;
}

void UserWidget::add()
{
  bool ok = false;
  auto text = QInputDialog::getText (
        this,
        tr( "Adding item" ),
        tr( "Item text:" ),
        QLineEdit::Normal,
        QTime::currentTime ().toString ( "hh:mm:ss ms" ),
        &ok );
  if ( ok ) {
    ui->content->addItem( text );
  }
}

void UserWidget::remove()
{
  if ( ui->content->currentRow() >= 0 ) {
    if ( QMessageBox::question (
           this,
           tr ( "Removing item" ),
           tr ( "Remove?" ),
           tr ( "Cansel" ),
           tr ( "Ok" ) ) == 1 ) {
      delete ui->content->item ( ui->content->currentRow() );
    }
  }
}
