package IceCream;
import IceCreamAbstract.IceCream;

public class Gelato extends IceCream {
    private final String type = "Dense and rich in flavour Italian ice cream.";
    private float butterfatContent;


    public Gelato(int portionsCount, String taste, String name, float rate, boolean lactoseFree, float buterfatContent) {
        super(portionsCount, taste, name, rate, lactoseFree);
        this.butterfatContent = buterfatContent;
    }

    public String getType() {
        return type;
    }

    public float getButterfatContent() {
        return butterfatContent;
    }

    public String getRecipe(){
        String recipe = "Here's your gelato recipe:\nIn a medium saucepan, mix milk and cream. Warm until foam forms around the edges. Remove from heat.\n";
        recipe = recipe + "In a large bowl, beat the egg yolks and sugar until frothy. Gradually pour the warm milk into the egg yolks, whisking constantly. ";
        recipe = recipe + "Add " + this.getTaste() + ".\nReturn mixture to saucepan; cook over medium heat, stirring with a wooden spoon until the mixture gels slightly and coats the back of the spoon.\n";
        recipe = recipe + "Pour the mixture through a sieve or fine strainer into a bowl. Cover, and chill for several hours or overnight.\nPour the mixture into an ice cream maker, and freeze according to the manufacturer's instructions.";
        return recipe;
    }
}
