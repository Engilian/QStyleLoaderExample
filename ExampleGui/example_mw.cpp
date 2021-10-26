#include "example_mw.h"
#include "ui_example_mw.h"

#include <QDir>
#include <QFile>
#include <QCoreApplication>

ExampleMainWindow::ExampleMainWindow(QWidget *parent)
  : QMainWindow(parent)
  , STYLE_PATH ( QDir::fromNativeSeparators(
                   QCoreApplication::applicationDirPath() +
                   "/style.css" ) )
  , ROW_COUNT( 5 )
  , COLUMN_COUNT( 5 )
  , COUNT( ROW_COUNT * COLUMN_COUNT )
  , m_current( 0 )
  , ui(new Ui::ExampleMainWindow)
{
  ui->setupUi(this);

  // Load style file to Editor
  QFile f ( STYLE_PATH );
  if ( f.open ( QIODevice::ReadOnly ) ) {
    ui->style->setPlainText(
          QString::fromUtf8( f.readAll() ) );
    f.close();
  }

  connect( ui->style, &QPlainTextEdit::textChanged,
           this,      &ExampleMainWindow::textChanged );

  // Create dynamic buttons
  for ( int row = 0; row < ROW_COUNT; ++row ) {
    for ( int column = 0; column < COLUMN_COUNT; ++column ) {
      auto b = new QPushButton( QString( "%1:%2" )
                                .arg ( row + 1 )
                                .arg ( column + 1 ) );
      b->setObjectName( "b" + QString::number( row * COLUMN_COUNT + column ) );
      ui->dynamicLay->addWidget ( b, row, column );
      m_buttons << b;
    }
  }

  startTimer( 1000 );
}

ExampleMainWindow::~ExampleMainWindow()
{
  delete ui;
}

void ExampleMainWindow::textChanged()
{
  QFile f ( STYLE_PATH );
  if ( f.open( QIODevice::WriteOnly ) ) {
    f.write( ui->style->toPlainText().toUtf8() );
    f.close();
  }
}

void ExampleMainWindow::timerEvent(QTimerEvent *)
{
  if ( m_current >= COUNT )
    m_current = 0;

  for ( int i = 0; i < COUNT; ++i ) {
    m_buttons[ i ]->setProperty( "current", m_current == i );
  }

  ++m_current;
}

