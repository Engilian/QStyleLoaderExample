#include "example_mw.h"

#include <QDir>
#include <QFile>
#include <QApplication>
#include <qstyle_loader.h>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Check contains style file
  QString path = QDir::fromNativeSeparators(
        QCoreApplication::applicationDirPath() +
        "/style.css" );
  if ( !QFile::exists( path ) )  {
    QFile out( path );
    if ( out.open( QIODevice::WriteOnly ) ) {
      QFile in( ":/style.css" );
      if ( in.open( QIODevice::ReadOnly ) ) {
        out.write( in.readAll() );
        in.close();
      }
      out.close();
    }
  }

  ExampleMainWindow w;

  // Create QStyleLoader object
  QStyleLoader style;

  // Adding style file
  style.addFile ( path );

  // Adding directory
  //style.addDirectory( "" );

  // Create updater for widget
  auto u = style.addUpdater( &w );
  u->add ( "current" );
  u->setRefreshChildWidgets( true );
//  u->setUpdateWithAllChanges( true );

  w.show();
  return a.exec();
}
