package progettovuoto;

import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=576,205");
    submodules:
        source: Source {
            @display("p=33,95");
        }
        queue2: Queue {
            @display("p=247,45");
        }
        queue1: Queue {
            @display("p=247,141");
        }
        sink: Sink {
            @display("p=382,95");
        }
        routermy: Routermy {
            @display("p=123,84");
        }
    connections:
        queue1.out --> sink.in++;
        queue2.out --> sink.in++;
        source.out --> routermy.in++;
        routermy.out++ --> queue2.in++;
        routermy.out++ --> queue1.in++;
}

