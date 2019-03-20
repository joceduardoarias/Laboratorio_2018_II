using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace proyectoClase02
{
    class Program
    {
        static void Main(string[] args)
        {   //INICIALIZO ATRIBUTO
            Sello.mensaje = " Hola new york ";
            Sello.color = ConsoleColor.Red;
            //LLAMADA METODO IMPRIMIR
            //Console.WriteLine(Sello.Imprimir());
            //LLAMADA METODO BORRAR
           // Sello.Borrar();
            //LLAMADA METODO IMPRIMIR
            Console.WriteLine(Sello.Imprimir());
            //LLAMADA METODO IMPRIMIR EN COLOR
            Sello.ImprimirEnColor();
            Console.WriteLine(Sello.Imprimir());
            Console.ReadKey();
            //fin consola

        }
    }
}
