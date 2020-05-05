package IceCream;
import IceCreamAbstract.IceCream;

public class Sorbet extends IceCream {
    private final String type = "It's ice cream made out of fruit of berries which can be served either cold or warm so you can drink it.";
    private int temperature;

    public String getType() {
        return type;
    }

    public int getTemperature() {
        return temperature;
    }

    public Sorbet(int portionsCount, String taste, String name, float rate, int temperature) {
        super(portionsCount, taste, name, rate, true);
        this.temperature = temperature;
    }

    public String getRecipe(){
        String recipe = "Here's your sorbet recipe:\nMix ";
        recipe = recipe + this.getTaste() + " with cooled sugar syrup and put it in the freezer. ";
        recipe = recipe + "In order to improve the texture of your sorbet mix it again while it freezes.";
        return recipe;
    }
}
