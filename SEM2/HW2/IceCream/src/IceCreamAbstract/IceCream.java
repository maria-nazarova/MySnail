
package IceCreamAbstract;

public abstract class IceCream {
    private int portionsCount;
    private String taste;
    private String name;
    private float rate;
    private boolean lactoseFree;

    public int getPortionsCount() {
        return portionsCount;
    }

    public String getTaste() {
        return taste;
    }

    public float getRate() { return rate; }

    public String getName() {
        return name;
    }
    public boolean isLactoseFree() {
        return lactoseFree;
    }

    public IceCream(int portionsCount, String taste, String name, float rate, boolean lactoseFree) {
        this.portionsCount = portionsCount;
        this.taste = taste;
        this.name = name;
        this.rate = rate;
        this.lactoseFree = lactoseFree;
    }

    public abstract String getRecipe();
}
