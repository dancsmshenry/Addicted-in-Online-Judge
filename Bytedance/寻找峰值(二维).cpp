/**
     * 找到二维数组中的一个峰值
     * @param arr
     * @param minColumn 列的中间找起
     * @return
     */
    public int findAPeakBaseTwoDimensional(int[][] arr,int minColumn) {
        int column=arr[0].length;
        int maxRowIndex = getMaxRowIndex(arr, minColumn);
        int target = arr[maxRowIndex][minColumn];
        //与左边对比，小则向左找峰值
        if(minColumn > 0 && target< arr[maxRowIndex][minColumn-1]){
          return  findAPeakBaseTwoDimensional(arr,minColumn -1);
        }
        //与右边对比，小则向右找峰值
        if(minColumn+1 < column  && target< arr[maxRowIndex][minColumn+1]){
           return findAPeakBaseTwoDimensional(arr,minColumn + 1);
        }
        //垂直方向上它是最大，水平方向上也是最大，所以它就是peak
        return target;
    }

    /**
     * 获取指定列上最大值的行下标
     * @param arr 二维数组
     * @param minColumn 指定列
     * @return
     */
    private int getMaxRowIndex(int[][] arr, int minColumn) {
        int max = -1,maxRowIndex = 0;
        for(int i=0,rowLen=arr.length;i<rowLen;i++){
             if( max < arr[i][minColumn] ){
                 max = arr[i][minColumn];
                 maxRowIndex = i;
             }
        }
        return maxRowIndex;
    }
