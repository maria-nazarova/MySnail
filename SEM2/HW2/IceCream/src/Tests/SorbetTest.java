package Tests;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import IceCream.Sorbet;


public class SorbetTest {
    private Sorbet sorbet;
    @Before
    public void setSorbet() {
        this.sorbet = new Sorbet(2, "Blueberry", "Blueberry Pie", 8.5f, -5);
    }

    @Test
    public void testGetType() {
        Assert.assertEquals(this.sorbet.getType(), "It's ice cream made out of fruit of berries which can be served either cold or warm so you can drink it.");
    }

    @Test
    public void testGetTemperature(){
        Assert.assertEquals(this.sorbet.getTemperature(), -5);
    }

    @Test
    public void testPrintRecipe() {
        Assert.assertEquals(this.sorbet.getRecipe(), "Here's your sorbet recipe:\nMix Blueberry with cooled sugar syrup and put it in the freezer. In order to improve the texture of your sorbet mix it again while it freezes.");
    }
}