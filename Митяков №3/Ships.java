
package ships;

import java.util.ArrayList;

public class Ships {


    public static void main(String[] args) {
       ArrayList<ship> Ships = new ArrayList<>();
       ship ship = new WarShips("Batillus", 1998, "ледокол", 590 );
       Ships.add(ship);
       Ships.add(new Avianos("Torin", 1959, "нефтегазоперевозка", 414));
       
       printShips(Ships);
    }
    
    public static void printShips(ArrayList<ship> Ships){
        for (ship ship : Ships){
            System.out.println("Name: " + ship.getName());
            System.out.println("Year: " + ship.getYear());
            System.out.println("Type: " + ship.getType());
            System.out.println("Lenght: " + ship.getLenght());
        }
    }
}
