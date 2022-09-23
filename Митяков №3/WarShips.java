
package ships;

public abstract class WarShips implements ship {
     private String name;
     private int year;
     private String type;
     private int Lenght;
    
     public WarShips (String name, int year, String type, int Lenght ){
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
