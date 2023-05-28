import java.util.Comparator;
class compareFreq implements Comparator<node> {
    public int compare(node x, node y)
    {
        return x.freq - y.freq;
    }
}