/**
 *
 * @author hardel
 */
public class SimplexTest {
    
    //llamar desde main()
    public void test() {
        boolean quit = false;
        
        /*Ejemplo:
          maximizar:  3x + 5y 
          condiciones: x +  y = 4
                       x + 3y = 6*/
        float[][] standardized =  {
                { 1,   1,    1,  0,   4},
                { 1,   3,    0,  1,   6},
                {-3,  -5,    0,  0,   0}
        };
        
        /*2 variables
          4 valores desconocidos*/
        Simplex simplex = new Simplex(2, 4);
        
        simplex.fillTable(standardized);

        //Para debugging
        //Imprimir Matriz
        /*System.out.println("---Inicializando---");
        simplex.print();*/
        
        //Si la Matriz(tabla simplex) no es optima iterar hasta llegar a una solucion
        while(!quit){
            Simplex.ERROR err = simplex.compute();
            
            //se encontro la mejor solucion
            if(err == Simplex.ERROR.IS_OPTIMAL) {
                simplex.print();
                quit = true;
            } else if(err == Simplex.ERROR.UNBOUNDED) {
                //el problema no se puede solucionar por simplex
                System.out.println("---Solution Ambigua---");
                quit = true;
            }
        }
    }
}
