package com.company;

import org.jgrapht.Graph;
import org.jgrapht.Graphs;
import org.jgrapht.alg.interfaces.ShortestPathAlgorithm;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.SimpleGraph;
import java.util.*;

public class LightOffPuzzle
{
    private int n;

    public void askSizeOfSquareGrid()
    {
        int n           = 0;
        boolean redo    = true;
        while (redo)
        {
            try
            {
                Scanner input = new Scanner(System.in);

                System.out.println("======================================================================");
                System.out.println(" ENTER THE SIZE OF GRID SQUARE (SIZE >= 3) : ");
                n = input.nextInt();
                if(n < 3)
                {
                    throw new InputMismatchException();
                }
                System.out.println("======================================================================");
                this.n = n;
                redo = false;
            }
            catch (InputMismatchException e)
            {
                System.out.println("----------------------------------------------------------------------");
                System.out.println(" [INPUT MISMATCH EXCEPTION] ");
            }
        }
    }

    public void askInitialState(ArrayList<Integer> InitialState)
    {
        String state;
        boolean redo = true;

        while (redo)
        {
            try
            {
                Scanner input = new Scanner(System.in);

                System.out.println("======================================================================");
                System.out.printf(" INITIAL STATES (%-2d BITS, LEFT TO RIGHT, LINE BY LINE) : \n",n*n);
                state = input.nextLine();
                if(state.length() != (n*n))
                {
                    throw new InputMismatchException("INPUT LENGTH != " + (n*n));
                }

                for(int i=0 ; i<(n*n) ; i++)
                {
                    if(state.charAt(i) != '0' && state.charAt(i) != '1')
                    {
                        throw new InputMismatchException("CHARACTER != (0 OR 1) DETECTED");
                    }

                    InitialState.add(Integer.parseInt(String.valueOf(state.charAt(i))));
                }
                System.out.println("======================================================================");
                System.out.println();
                redo = false;

            }
            catch (InputMismatchException e)
            {
                System.out.println("----------------------------------------------------------------------");
                System.out.println(" [INPUT MISMATCH EXCEPTION : " + e.getMessage() + "]");
            }
        }
    }

    public boolean askTryAgain()
    {
        String in;
        boolean redo    = true;
        boolean running = false;
        while (redo)
        {
            try
            {
                Scanner input = new Scanner(System.in);

                System.out.println("======================================================================");
                System.out.println(" DO YOU WANT TO TRY AGAIN? (Y/N) : ");
                in = input.nextLine();
                if(in.equalsIgnoreCase("Y"))
                {
                    running = true;
                }
                else if(in.equalsIgnoreCase("N"))
                {
                    running = false;
                }
                else
                {
                    throw new InputMismatchException();
                }
                System.out.println("======================================================================");
                System.out.println();
                System.out.println();
                System.out.println();
                redo = false;
            }
            catch (InputMismatchException e)
            {
                System.out.println("----------------------------------------------------------------------");
                System.out.println(" [INPUT MISMATCH EXCEPTION] ");
            }
        }
        return running;
    }

    public ArrayList<Integer> DecimalToBit(int decimal)
    {
        StringBuilder bit = new StringBuilder();
        bit.append(Integer.toBinaryString(decimal));

        if(bit.length()!=(n*n))
        {
            StringBuilder temp = new StringBuilder();
            for(int i=0 ; i<((n*n) - bit.length()) ; i++)
            {
                temp.append("0");
            }

            temp.append(bit);
            bit = temp;
        }

        ArrayList<Integer> state = new ArrayList<Integer>();

        for(int i=0 ; i<bit.length() ; i++)
        {
            state.add(((bit.charAt(i)) - 48));
        }

        return state;
    }

    public int BitToDecimal(ArrayList<Integer> bit)
    {
        int decimal  = 0;

        for(int i=0 ; i<bit.size() ; i++)
        {
            int t = bit.get(i);
            if(t == 1)
            {
                decimal += Math.pow(2,((n*n)-1)-i);
            }
        }

        return decimal;
    }

    public void findMinimumMove(ArrayList<Integer> InitialState)
    {
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        HashSet<Integer> d = new HashSet<>();
        Graph<Integer, DefaultEdge> g = new SimpleGraph<Integer, DefaultEdge>(DefaultEdge.class);

        q.add(InitialState);

        int initialValue = BitToDecimal(InitialState);

        try
        {
            while(!g.containsVertex(0))
            {
                ArrayList<Integer> state = new ArrayList<Integer>(q.poll());
                int value = BitToDecimal(state);

                if(!d.contains(value))
                {
                    d.add(value);

                    for (int i=0 ; i<state.size() ; i++)
                    {
                        ArrayList<Integer> newState = toggle(new ArrayList<>(state),i);
                        int newValue = BitToDecimal(newState);
                        q.add(newState);
                        Graphs.addEdgeWithVertices(g,value,newValue);
                    }
                }
            }
        }
        catch (NullPointerException e)
        {
            System.out.println("[CANNOT FIND MINIMUM MOVE(S)]");
            return;
        }

        ShortestPathAlgorithm<Integer,DefaultEdge> SH_Path = null;

        try
        {
            SH_Path = new DijkstraShortestPath<Integer, DefaultEdge>(g);

            if(SH_Path.getPath(initialValue,0) != null)
            {
                System.out.println();
                System.out.println("======================================================================");
                System.out.printf(" MINIMUM MOVE(S) TO TURN ALL LIGHTS OFF : %-2.0f\n",SH_Path.getPath(initialValue, 0).getWeight());
                System.out.println("======================================================================");
            }
        }
        catch (IllegalArgumentException e)
        {
            System.out.println("[SHORTEST PATH ERROR]");
            return;
        }

        printMove(initialValue,SH_Path);
    }

    public void printMove(int initialValue,ShortestPathAlgorithm SH_Path)
    {
        List<Integer> allMoveValue = SH_Path.getPath(initialValue,0).getVertexList();

        for(int i=1 ; i<allMoveValue.size() ; i++)
        {
            ArrayList<Integer> RowAndColumn = calculateToggledPosition(DecimalToBit(allMoveValue.get(i-1)),DecimalToBit(allMoveValue.get(i)));

            String turnOnOrOff;

            if(RowAndColumn.get(2) == 0)
            {
                turnOnOrOff = "TURN OFF";
            }
            else
            {
                turnOnOrOff = "TURN ON";
            }

            System.out.println();
            System.out.println("======================================================================");
            System.out.printf(" MOVE (%2d) : %s ROW %d | COLUMN %d \n",i,turnOnOrOff,RowAndColumn.get(0),RowAndColumn.get(1));
            printTable(DecimalToBit(allMoveValue.get(i)));
        }
    }

    public void printTable(ArrayList<Integer> state)
    {
        int count       = 0;
        int row         = 0;
        StringBuilder bit = new StringBuilder("");

        System.out.println("----------------------------------------------------------------------");
        System.out.printf("         ");
        for(int i=0 ; i<n ; i++)
        {
            System.out.printf("|  COL %-2d ",i);
        }
        System.out.println("|");

        for(Integer t : state)
        {
            bit.append(t);

            if(count == 0)
            {
                System.out.printf(" ROW %-2d  ",row);
            }

            System.out.printf("|    %-1d    ",t);

            if(count == n-1)
            {
                System.out.println("|");
                count = -1;
                row++;
            }
            count++;
        }

        System.out.println("----------------------------------------------------------------------");
        System.out.printf(" BIT STRING : %s \n",bit);
        System.out.printf(" DECIMAL ID : %d \n", BitToDecimal(state));
        System.out.println("======================================================================");
    }

    public ArrayList<Integer> calculateToggledPosition(ArrayList<Integer> beforeState, ArrayList<Integer> afterState)
    {
        int column  = 404;
        int row     = 404;
        int OnOrOff = 404;

        for(int i=0 ; i<beforeState.size() ; i++)
        {
            if(afterState.get(i) != beforeState.get(i))
            {
                //========================================[   TOP LEFT   ]========================================//
                if(i == 0)
                {
                    if((afterState.get(i+1) != beforeState.get(i+1)) && (afterState.get(i+n) != beforeState.get(i+n)))
                    {
                        column = 0;
                        row    = 0;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[     TOP      ]========================================//
                else if((i > 0) && (i<(n-1)))
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i+1) != beforeState.get(i+1)) && (afterState.get(i+n) != beforeState.get(i+n)))
                    {
                        column = i;
                        row    = 0;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[   TOP RIGHT  ]========================================//
                else if(i==(n-1))
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i+n) != beforeState.get(i+n)))
                    {
                        column = n-1;
                        row    = 0;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[     LEFT     ]========================================//
                else if((i >= n) && (i<((n-1)*n)) && (i%n == 0))
                {
                    if((afterState.get(i+1) != beforeState.get(i+1)) && (afterState.get(i+n) != beforeState.get(i+n)) && (afterState.get(i-n) != beforeState.get(i-n)))
                    {
                        column = 0;
                        row    = i/n;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[     RIGHT    ]========================================//
                else if((i<(n*n)-1) && (i>n-1) && (i%n == (n-1)))
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i+n) != beforeState.get(i+n)) && (afterState.get(i-n) != beforeState.get(i-n)))
                    {
                        column = n-1;
                        row    = i/n;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[  BOTTOM LEFT ]========================================//
                else if((i == ((n-1)*n)))
                {
                    if((afterState.get(i-n) != beforeState.get(i-n)) && (afterState.get(i+1) != beforeState.get(i+1)))
                    {
                        column = 0;
                        row    = n-1;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[    BOTTOM    ]========================================//
                else if((i > ((n-1)*n)) && (i<(n*n)-1))
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i+1) != beforeState.get(i+1)) && (afterState.get(i-n) != beforeState.get(i-n)))
                    {
                        column = i%n;
                        row    = n-1;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[ BOTTOM RIGHT ]========================================//
                else if((i == ((n*n)-1)))
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i-n) != beforeState.get(i-n)))
                    {
                        column = n-1;
                        row    = n-1;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
                //========================================[    MIDDLE    ]========================================//
                else
                {
                    if((afterState.get(i-1) != beforeState.get(i-1)) && (afterState.get(i+1) != beforeState.get(i+1)) && (afterState.get(i-n) != beforeState.get(i-n)) && (afterState.get(i+n) != beforeState.get(i+n)))
                    {
                        column = i%n;
                        row    = i/n;
                        if(beforeState.get(i) == 0)
                        {
                            OnOrOff = 1;
                        }
                        else
                        {
                            OnOrOff = 0;
                        }
                    }
                }
            }
        }

        ArrayList<Integer> RowAndColumn = new ArrayList<Integer>();

        RowAndColumn.add(row);
        RowAndColumn.add(column);
        RowAndColumn.add(OnOrOff);
        return RowAndColumn;
    }

    public ArrayList<Integer> toggle(ArrayList<Integer> state, int i)
    {
        toggle_bit(state,i);
        //========================================[   TOP LEFT   ]========================================//
        if(i == 0)
        {
            toggle_bit(state,i+1);
            toggle_bit(state,i+n);
        }
        //========================================[     TOP      ]========================================//
        else if((i > 0) && (i<(n-1)))
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i+1);
            toggle_bit(state,i+n);
        }
        //========================================[   TOP RIGHT  ]========================================//
        else if(i==(n-1))
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i+n);
        }
        //========================================[     LEFT     ]========================================//
        else if((i >= n) && (i<((n-1)*n)) && (i%n == 0))
        {
            toggle_bit(state,i+1);
            toggle_bit(state,i+n);
            toggle_bit(state,i-n);
        }
        //========================================[     RIGHT    ]========================================//
        else if((i<(n*n)-1) && (i>n-1) && (i%n == (n-1)))
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i+n);
            toggle_bit(state,i-n);
        }
        //========================================[  BOTTOM LEFT ]========================================//
        else if(i == ((n-1)*n))
        {
            toggle_bit(state,i-n);
            toggle_bit(state,i+1);
        }
        //========================================[    BOTTOM    ]========================================//
        else if((i > ((n-1)*n)) && (i<(n*n)-1))
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i+1);
            toggle_bit(state,i-n);
        }
        //========================================[ BOTTOM RIGHT ]========================================//
        else if(i == ((n*n)-1))
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i-n);
        }
        //========================================[    MIDDLE    ]========================================//
        else
        {
            toggle_bit(state,i-1);
            toggle_bit(state,i+1);
            toggle_bit(state,i-n);
            toggle_bit(state,i+n);
        }

        return state;
    }

    public void toggle_bit(ArrayList<Integer> state,int i)
    {
        if(state.get(i) == 1) { state.set(i,0); }
        else { state.set(i,1); }
    }

    public static void main(String[] args)
    {
        boolean running = true;

        while(running)
        {
            LightOffPuzzle main = new LightOffPuzzle();
            ArrayList<Integer> InitialState = new ArrayList<Integer>();

            main.askSizeOfSquareGrid();
            main.askInitialState(InitialState);

            System.out.println("===========================[INITIAL STATES]===========================");
            main.printTable(InitialState);
            main.findMinimumMove(InitialState);
            running = main.askTryAgain();
        }
    }
}
