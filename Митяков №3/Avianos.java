
package ships;

public class Avianos extends WarShips {
         private String name;
         private int year;
         private String type;
         private int Lenght;
         
         public Avianos(String name, int year, String type, int Lenght) {
            super(name, year , type, Lenght);
            this.name = name;
            this.year = year;
            this.type = type;
            this.Lenght = Lenght;
     }
    @Override
    public String getName() {
        return name;
    }
 
    @Override
    public int getYear() {
        return year;
    }
 
    @Override
    public String getType() {
        return type;
    }
 
 
    @Override
    public int getLenght() {
        return Lenght;
    }
}