#ifdef QT_QML_DEBUG
#include <QtQuick>
#include <QGeoCoordinate>
#include <QGeoRectangle>
#include <QGeoAreaMonitorInfo>
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include <QGeoLocation>
#include <QGeoAddress>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#endif

#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/untitled3.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    /*
    QVariantMap map;
    for (int i = 1; i < argc; i += 2) {
        map["x"][i / 2] = argv[i];
        map["y"][i / 2] = argv[i + 1];
    }
    QVariant v = map;
    QMetaObject::invokeMethod(object, "/qml/untitled3.qml",
                                  Q_RETURN_ARG(QVariant, returnedValue),
                                  Q_ARG(QVariant,v));
    return SailfishApp::main(argc, argv);
    */

    //QGuiApplication* app =  SailfishApp::application(argc, argv);
    /*
    QQuickView* view = SailfishApp::createView();
    view->engine()->addImportPath("/usr/lib/untitled3/");
    view->setSource(SailfishApp::pathTo("qml/untitled3.qml"));
    view->showFullScreen();
    QObject::connect(view->engine(), &QQmlEngine::quit, app, &QGuiApplication::quit);
    return app->exec();
    */

    /*
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("SailfishMap");

    QCommandLineParser parser;
    QCommandLineOption areaDisplayOption(QStringList() << "a",
           QCoreApplication::translate("main", "Display map area fitting in rectangle of points (x1; y1), (x2; y2)"));
    QCommandLineOption itemDisplayOption(QStringList() << "i",
           QCoreApplication::translate("main", "Overwrite existing files."));

    parser.addOption(areaDisplayOption);
    parser.addOption(itemDisplayOption);

    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    // source is args.at(0), destination is args.at(1)
    */

    bool areaIsSet = false;
    bool itemsAreSet = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0) {
            areaIsSet = true;
        }
        if (strcmp(argv[i], "-i") == 0) {
            itemsAreSet = true;
        }
    }
    std::cout << areaIsSet << " " << itemsAreSet << std::endl;

    //QGuiApplication* app =  SailfishApp::application(argc, argv);
    //QQuickView* view = SailfishApp::createView();
    //view->engine()->addImportPath("/usr/lib/counter-cpp-application/");
    //view->setSource(SailfishApp::pathTo("qml/counter-cpp-application.qml"));
    //view->showFullScreen();
    //QObject::connect(view->engine(), &QQmlEngine::quit, app, &QGuiApplication::quit);
    //return app->exec();


    QGuiApplication* app =  SailfishApp::application(argc, argv);
    QQuickView* view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/SailfishMap.qml"));

    /*
    QQuickItem *root = dynamic_cast<QQuickItem*>(view->rootObject());
    QQuickItem *map = root->findChild<QQuickItem*>("map");
    if (map) {
        //object->se
        QQmlComponent component(view->engine());
        component.setData("import QtQuick 2.2 \n\
                          import QtPositioning 5.3 \n\
                          import QtLocation 5.0 \n\
                          \n\
                          \n\
                          MapQuickItem { \n\
                              id: mapItem \n\
                              coordinate: QtPositioning.coordinate(59.91, 10.75)\
                              anchorPoint.x: image.width / 2 \n\
                              anchorPoint.y: image.height \n\
                          }", QUrl());
          QQuickItem *new_item = qobject_cast<QQuickItem*>(component.create());
          if (new_item) {
              new_item->setParentItem(root->findChild<QQuickItem*>("map"));
              //new_item->setParent(view);
              if (new_item->isVisible()) {
                  std::cout << "success\n";
              }
              //new_item->setVisible(true);
              //QQmlEngine::setObjectOwnership(new_item, QQmlEngine::CppOwnership);
              std::cout << "asd\n";
              //new_item->setParent(view);
              //new_item->setVisible(true);
              //new_item->set
              //new_item->setProperty("coordinate", QVariant::fromValue(QGeoCoordinate(59.91, 10.76)));
              //QQuickItem *textRectangle = new_item->findChild<QQuickItem*>("textRectangle");
              //textRectangle->setProperty("text", "New item");
              //textRectangle->setVisible(true);
              //new_item->setProperty("text","321");
              //map->sta
              //view->
          }
        //while (!component.isReady()) {}
        //if (component.isReady()) {
       // }
    }

    if (map) {
        //object->se
        QQmlComponent component(view->engine(), QUrl(QStringLiteral("qrc:/qml/MapQuickItem.qml")), QQmlComponent::PreferSynchronous);
        QQuickItem *new_item = qobject_cast<QQuickItem*>(component.create());
        QQmlEngine::setObjectOwnership(new_item, QQmlEngine::CppOwnership);
        new_item->setParentItem(map);
        new_item->setParent(view);
        //new_item->set
        new_item->setProperty("coordinate", QVariant::fromValue(QGeoCoordinate(59.91, 10.76)));
        QQuickItem *textRectangle = new_item->findChild<QQuickItem*>("textRectangle");
        textRectangle->setProperty("text", "New item");
        //new_item->setProperty("text","321");
    }
    */



    //QQmlComponent component(view->engine(), QUrl::fromLocalFile("qrc:qml/main.qml"));
    //QObject *object = component.create();
    int index = 1;
    QQuickItem *root = dynamic_cast<QQuickItem*>(view->rootObject());
    for (int j = 0; j < 2; ++j) {
        if (areaIsSet && strcmp(argv[index], "-a") == 0) {
            QQuickItem *mapRectangle = root->findChild<QQuickItem*>("transparentMapRectangle");
            if (mapRectangle) {
                ++index;
                mapRectangle->setProperty("topLeft.latitude", argv[index++]);
                mapRectangle->setProperty("topLeft.longitude", argv[index++]);
                mapRectangle->setProperty("bottomRight.latitude", argv[index++]);
                mapRectangle->setProperty("bottomRight.longitude", argv[index++]);
                mapRectangle->setProperty("color", "blue");
                mapRectangle->setObjectName("mapRectangle");
                areaIsSet = false;
            }
        }

        if (itemsAreSet && strcmp(argv[index], "-i") == 0) {
            std::cout << std::endl;
            int last = argc;
            if (areaIsSet) {
                last -= 5;
            }
            ++index;
            for (int i = index; i < last; i += 3) {
                QString s = "item";
                s += char((last - i) / 3) + '0';
                std::cout << s.toStdString() << std::endl;
                QQuickItem *mapItem = root->findChild<QQuickItem*>(s);
                if (mapItem) {
                    double latitude = atof(argv[index++]);
                    double longitude = atof(argv[index++]);
                    std::cout << latitude << " " << longitude << std::endl;
                    auto coord = QGeoCoordinate(latitude, longitude);
                    mapItem->setProperty("coordinate", QVariant::fromValue(coord));
                    QQuickItem *textBox = root->findChild<QQuickItem*>(s + "TextBox");
                    if (textBox) {
                        textBox->setProperty("text", argv[index++]);
                    }
                    mapItem->setObjectName(s + "Updated");
                }
            }
        }

        if (index == argc) {
            break;
        }
    }
    //QQmlComponent *component = new QQmlComponent(view->engine());
    //QObject::connect(view->engine(), SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));
    //view->engine()
    //view->engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    std::cout << argc << std::endl;



    //view->engine()->addImportPath("/usr/lib/untitled3/");

    view->showFullScreen();
    QObject::connect(view->engine(), &QQmlEngine::quit, app, &QGuiApplication::quit);
    return app->exec();
}
