package Main;
import IceCream.*;
import IceCreamAbstract.IceCream;


public class Main {
    public static void main(String[] args){
        Gelato myFav = new Gelato(1, "Blackcurrant",
                "Deep Ocean", 9.9f, false, 3.6f);
        Sorbet kidsFav = new Sorbet (4, "Strawberry", "Cotton Candy", 7.8f, -2);

        String gelatoRecipe = myFav.getRecipe();
        System.out.println(gelatoRecipe);
        System.out.println();
        String sorbetRecipe = kidsFav.getRecipe();
        System.out.println(sorbetRecipe);
    }
}
