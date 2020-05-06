package Tests;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import IceCream.Gelato;


public class GelatoTest {
    Gelato gelato;
    @Before
    public void setGelato() {
        gelato = new Gelato(2, "Chocolate", "Chocolate Shock", 8.8f, false, 5.7f);

    }

    @Test
    public  void testGetType(){
        Assert.assertEquals(gelato.getType(), "Dense and rich in flavour Italian ice cream.");
    }

    @Test
    public void testGetButterfatContent() {
        Assert.assertEquals(gelato.getButterfatContent(), 5.7f, 0.05);
    }

    @Test
    public void testGetRecipe() {
        Assert.assertEquals(gelato.getRecipe(), "Here's your gelato recipe:\n" +
                "In a medium saucepan, mix milk and cream. Warm until foam forms around the edges. Remove from heat.\n" +
                "In a large bowl, beat the egg yolks and sugar until frothy. Gradually pour the warm milk into the egg yolks, whisking constantly. Add Chocolate.\n" +
                "Return mixture to saucepan; cook over medium heat, stirring with a wooden spoon until the mixture gels slightly and coats the back of the spoon.\n" +
                "Pour the mixture through a sieve or fine strainer into a bowl. Cover, and chill for several hours or overnight.\n" +
                "Pour the mixture into an ice cream maker, and freeze according to the manufacturer's instructions.");
    }
}