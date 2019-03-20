using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace proyectoClase02
{
    public class Sello
    {
        //Atributos
        public static string mensaje;
        public static ConsoleColor color;
        //Metodos
        public static string Imprimir()
        {
            return Sello.ArmarFormatoMensaje();
        }
        public static void Borrar ()
        {
            Sello.mensaje = "";
        }
        //Metodo cambia color y vuelve a colocar el color original
        public static void ImprimirEnColor()
        {
            Console.ForegroundColor = Sello.color;
            Console.WriteLine (Sello.Imprimir());
            Console.ForegroundColor = ConsoleColor.DarkGray;
        }
        private static string ArmarFormatoMensaje()
        {
            int n,i;
            string mensajaFormato = "";
            n = Sello.mensaje.Length;
            for(i=0;i<n+2;i++)
            {
                mensajaFormato += "*";
            }
            mensajaFormato += "\n*" + Sello.mensaje + "*\n" + mensajaFormato;

            return mensajaFormato;
        }
    }
}
