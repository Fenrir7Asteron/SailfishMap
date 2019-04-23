#ifdef QT_QML_DEBUG
#include <QtQuick>
#include <QGeoCoordinate>
#include <QGeoRectangle>
#include <QDebug>
#include <cstdlib>
#endif

#include <sailfishapp.h>

int main(int argc, char *argv[])
{
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

    QGuiApplication* app =  SailfishApp::application(argc, argv);
    QQuickView* view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/SailfishMap.qml"));

    int index = 1;
    bool tAreaIsSet = areaIsSet;
    QQuickItem *root = dynamic_cast<QQuickItem*>(view->rootObject());
    for (int j = 0; j < 2; ++j) {
        if (tAreaIsSet && strcmp(argv[index], "-a") == 0) {
            QQuickItem *mapRectangle = root->findChild<QQuickItem*>("transparentMapRectangle");
            if (mapRectangle) {
                ++index;
                mapRectangle->setProperty("lLatitude", argv[index++]);
                mapRectangle->setProperty("lLongitude", argv[index++]);
                mapRectangle->setProperty("rLatitude", argv[index++]);
                mapRectangle->setProperty("rLongitude", argv[index++]);
                mapRectangle->setProperty("color", "blue");
                mapRectangle->setObjectName("mapRectangle");
                tAreaIsSet = false;
                continue;
            }
        }

        if (itemsAreSet && strcmp(argv[index], "-i") == 0) {
            int last = argc;
            if (tAreaIsSet) {
                last -= 5;
            }
            ++index;
            for (int i = index; i < last; i += 3) {
                QString s = "item";
                s += char((last - i) / 3) + '0';
                QQuickItem *mapItem = root->findChild<QQuickItem*>(s);
                if (mapItem) {
                    double latitude = atof(argv[index++]);
                    double longitude = atof(argv[index++]);
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

    index = 1;
    for (int j = 0; j < 2; ++j) {
        if (areaIsSet && strcmp(argv[index], "-a") == 0) {
            QQuickItem *mapRectangle = root->findChild<QQuickItem*>("cover_transparentMapRectangle");
            if (mapRectangle) {
                ++index;
                mapRectangle->setProperty("lLatitude", argv[index++]);
                mapRectangle->setProperty("lLongitude", argv[index++]);
                mapRectangle->setProperty("rLatitude", argv[index++]);
                mapRectangle->setProperty("rLongitude", argv[index++]);
                mapRectangle->setProperty("color", "blue");
                mapRectangle->setObjectName("cover_mapRectangle");
                areaIsSet = false;
                continue;
            }
        }

        if (itemsAreSet && strcmp(argv[index], "-i") == 0) {
            int last = argc;
            if (areaIsSet) {
                last -= 5;
            }
            ++index;
            for (int i = index; i < last; i += 3) {
                QString s = "cover_item";
                s += char((last - i) / 3) + '0';
                QQuickItem *mapItem = root->findChild<QQuickItem*>(s);
                if (mapItem) {
                    double latitude = atof(argv[index++]);
                    double longitude = atof(argv[index++]);
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

    view->showFullScreen();
    QObject::connect(view->engine(), &QQmlEngine::quit, app, &QGuiApplication::quit);
    return app->exec();
}
