using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace proyecto01
{
    class ejercicio01
    {
        static void Main(string[] args)
        {
            int valor;
            int primo;
            int i;
            int contador = 0;
            valor = int.Parse( Console.ReadLine());

            for (i=1;i<=valor;i++)
            {
                if(valor%i == 0)
                {
                    contador++;
                }
            }


        }
    }
}
