#include "dialog.h"

#include <QApplication>
#include <QDebug>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");  // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.write(2, 1, "Hello World!");
    xlsx.saveAs("Test.xlsx");       // save the document as 'Test.xlsx'
    QVariant data = xlsx.read("A1");
    qDebug() << data.type() << data.toString();
    data = xlsx.read(2, 1);
    qDebug() << data.type() << data.toString();

    Dialog w;
    w.show();
    return a.exec();
}
