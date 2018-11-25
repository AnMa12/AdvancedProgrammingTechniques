package com.company;

import static jdk.nashorn.internal.runtime.JSType.toInteger;

public class Main {

    public static void RadixSort(Integer[] array, int radix) {
        if (array.length == 0) {
            return;
        }

        // Determine minimum and maximum values
        int minValue = array[0];
        int maxValue = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] < minValue) {
                minValue = array[i];
            } else if (array[i] > maxValue) {
                maxValue = array[i];
            }
        }

        // Perform counting sort on each exponent/digit,
        // starting at the least significant digit
        int exponent = 1;
        while ((maxValue - minValue) / exponent >= 1) {
            countingSortByDigit(array, radix, exponent, minValue);
            exponent *= radix;
        }
    }

    public static void main(String[] args) {
        Integer[] a = new Integer[] {41,82,42,53,59,52,43};
        RadixSort(a, 10);
        for(int i = 0; i < a.length; i++)
            System.out.println(toInteger(a[i]));
    }

    private static void countingSortByDigit(
        Integer[] array, int radix, int exponent, int minValue) {
        int bucketIndex;
        int[] buckets = new int[radix];
        int[] output = new int[array.length];

        // Initialize bucket
        for (int i = 0; i < radix; i++) {
            buckets[i] = 0;
        }

        // Count frequencies
        for (int i = 0; i < array.length; i++) {
            bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
            buckets[bucketIndex]++;
        }

        // Compute cumulates
        for (int i = 1; i < radix; i++) {
            buckets[i] += buckets[i - 1];
        }

        // Move records
        for (int i = array.length - 1; i >= 0; i--) {
            bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
            output[--buckets[bucketIndex]] = array[i];
        }

        // Copy back
        for (int i = 0; i < array.length; i++) {
            array[i] = output[i];
        }
    }
}