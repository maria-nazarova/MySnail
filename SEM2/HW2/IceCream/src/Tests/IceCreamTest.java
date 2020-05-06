package Tests;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import IceCream.*;
import IceCreamAbstract.IceCream;

public class IceCreamTest {
    private IceCream sorbet;
    private IceCream gelato;

    @Before
    public void setIceCream(){
        sorbet = new Sorbet(1, "Lemon", "Depression", 7.7f, 10);
        gelato = new Gelato(3, "Raspberry", "Disappointment", 9.5f, false, 4.2f);
    }

    @Test
    public void testGetPortionsCount() {
        Assert.assertEquals(sorbet.getPortionsCount(), 1);
        Assert.assertEquals(gelato.getPortionsCount(),3);
    }

    @Test
    public void testGetTaste() {
        Assert.assertEquals(sorbet.getTaste(), "Lemon");
        Assert.assertEquals(gelato.getTaste(), "Raspberry");
    }

    @Test
    public void testGetRate() {
        Assert.assertEquals(sorbet.getRate(), 7.7f, 0.05);
        Assert.assertEquals(gelato.getRate(), 9.5f, 0.05);
    }

    @Test
    public void testGetName() {
        Assert.assertEquals(sorbet.getName(), "Depression");
        Assert.assertEquals(gelato.getName(), "Disappointment");
    }

    @Test
    public void testIsLactoseFree() {
        Assert.assertEquals(sorbet.isLactoseFree(), true);
        Assert.assertEquals(gelato.isLactoseFree(), false);
    }

}