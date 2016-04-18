#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main()
{
  /* Esta instruccion permite utilizar 'cout' del mismo modo que en C++,
   * con los agregados que proveen las clases de Qt, tales como manejo de streams,
   * strings, conversiones, locales... */
  QTextStream cout (stdout, QIODevice::WriteOnly);

  QList <QStringList> data;
  QFile file ("sample.csv");

  if (file.open(QIODevice::ReadOnly))
  {
    QTextStream stream (&file); //Defino un nuevo stream en el cual voy a ingresar la info que leo desde el archivo.

    forever //Este loop se ejecutará siempre, hasta que se rompa con break;
    {
      QString line = stream.readLine(); //Levanto una linea del archivo y la coloco en una QString.

      if (line.isNull()){break;} //prueba por si la string es nula (String())
      if (line.isEmpty()){break;} //prueba por si la string es vacía (String(""))

      QStringList row;
      foreach (const QString& cell, line.split("\n"))
      {
        row.append(cell.trimmed());
        cout << line << endl;
      }

      data.append(row); //agrego la linea leida desde el archivo al arreglo de QStrings.
    }
  }
  else {
    cout << "No se encuentra el archivo especificado o el mismo no puede abrirse." << endl;
  }

  return 0;
}
