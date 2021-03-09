#include "dialog.h"

#include <QApplication>
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
    xlsx.saveAs("Test.xlsx");       // save the document as 'Test.xlsx'

    Dialog w;
    w.show();
    return a.exec();
}
