package com.company;

import java.util.ArrayList;
import java.util.LinkedList;

import static jdk.nashorn.internal.runtime.JSType.toInteger;

public class Main {


    public static void BucketSort(Integer[] array, Integer bucketSize) {
        if(array.length == 0)
            return;
        else {
            //find the minim value in the array
            //find the maximum value in the array
            Integer minValue = array[0];
            Integer maxValue = array[0];
            for(int i = 1; i < array.length; i++) {
                if(array[i] > maxValue)
                    maxValue = array[i];
                if(array[i] < minValue)
                    minValue = array[i];
            }

            //make the buckets
            int numberOfBuckets = (maxValue - minValue)/bucketSize + 1;
            ArrayList<LinkedList<Integer>> buckets = new ArrayList<LinkedList<Integer>>(numberOfBuckets);
            //initialise all the buckets in the array list
            for(int i = 0; i < numberOfBuckets; i++) {
                buckets.add(new LinkedList<Integer>());
            }

            //put the array values in the buckets
            for(int i = 0; i < array.length; i++) {
                int position = (array[i]-minValue)/bucketSize;
                buckets.get(position).add(array[i]);
            }

            //travere each bucket and sort it + add them back into input array
            int currentIndex = 0;
            for(int i = 0; i < buckets.size(); i++) {
                Integer[] currentBucketArray = new Integer[buckets.get(i).size()];
                currentBucketArray = buckets.get(i).toArray(currentBucketArray);
                InsertionSort(currentBucketArray);
                for (int j = 0; j < currentBucketArray.length; j++) {
                    array[currentIndex++] = currentBucketArray[j];
                }
            }
        }
    }

    public static void InsertionSort(Integer[] list)
    {
        for (int i = 1; i < list.length; i++) {
            Integer item = list[i];
            int indexHole = i;
            while (indexHole > 0 && list[indexHole - 1] > item) {
                list[indexHole] = list[--indexHole];
            }
            list[indexHole] = item;
        }
    }

    public static void main(String[] args) {
        Integer[] a = new Integer[] {4,8,2,3,9,2,3};
        BucketSort(a, 5);
        for(int i = 0; i < a.length; i++)
            System.out.println(toInteger(a[i]));
    }
}
