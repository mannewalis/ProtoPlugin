#include "protowidget.h"
#include "protowidgetplugin.h"

#include <QtPlugin>

ProtoWidgetPlugin::ProtoWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ProtoWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ProtoWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ProtoWidgetPlugin::createWidget(QWidget *parent)
{
    return new ProtoWidget(parent);
}

QString ProtoWidgetPlugin::name() const
{
    return QLatin1String("ProtoWidget");
}

QString ProtoWidgetPlugin::group() const
{
    return QLatin1String("BLORGY");
}

QIcon ProtoWidgetPlugin::icon() const
{
    return QIcon();
}

QString ProtoWidgetPlugin::toolTip() const
{
    return QLatin1String("proto widget");
}

QString ProtoWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ProtoWidgetPlugin::isContainer() const
{
    return false;
}

QString ProtoWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"ProtoWidget\" name=\"protoWidget\">\n</widget>\n");
}

QString ProtoWidgetPlugin::includeFile() const
{
    return QLatin1String("protowidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(protowidgetplugin, ProtoWidgetPlugin)
#endif // QT_VERSION < 0x050000
