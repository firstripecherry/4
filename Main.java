package com.company;

import java.util.*;
import java.util.concurrent.ConcurrentLinkedDeque;

public class Main {
    public static final int size=10;

    public static ArrayDeque<Integer> stack = new ArrayDeque<>();

    public static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Чтобы начать игру введите число" );
        int num = scanner.nextInt();
        stack.addLast(num);
        secondThread secondThread = new secondThread();
        secondThread.start();
        while (true){
            num=scanner.nextInt();
            try{
                if(num==stack.peekLast()+1) stack.addLast(num); //проверяем правильность ввода
                else System.out.println("Ошибка!");
            }catch (EmptyStackException e){//если пока Scanner ждет secondThread удалил поседний элем
                break;
            }

            System.out.println("\n"+stack+"\n");
        }
    }




    public static class secondThread extends Thread{
        public secondThread(){

            while (!stack.isEmpty()&&stack.size()<size){

                try {
                    Thread.sleep(1500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if(stack.size()>=size-1){break;}
                stack.pollLast();
                System.out.println("\n"+stack+"\n");

            }
            System.out.println("Игра окончена");
            System.exit(0); //scanner все еще ожидает ввода, выходим из программы
        }
    }

}
