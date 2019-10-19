# surface-normal
**This is a tools code repo for CVPR2019 paper 1899: Deep Surface Normal Guided Depth Prediction for Outdoor Secene from Sparce Lidar Data and Single Color Image,by Jiaxiong Qiu, Zhaopeng Cui, Yinda Zhang, Xingdi Zhang, Shuaicheng Liu, Bing Zeng and Marc Pollefeys.**  

The main code is in [here](https://github.com/JiaxiongQ/DeepLiDAR)

The toolbox consists of some tools you might need for preparing the training data .  

## calplane-normal  
The most important one is the  ```Mat calplanenormal(Mat &src);```  

This function calculate the surface normal of the sparce lidar input, it will return a Mat res as the surface normal.
You should set `fcxcy ,windowsize, threshold` before use the function.  

The following functions are used in `Mat calplanenormal(Mat &src)`:  

`void cvFitPlane(const CvMat* points, float* plane);`  

`void CallFitPlane(const Mat& depth,int * points,int i,int j,float *plane12);`  

`void search_plane_neighbor(Mat &img,int i,int j ,float threhold,int* result);`  

`int telldirection(float * abc,int i,int j,float d); `  

 ***
So if you need a clean code , you can download the **clean.hpp**.  

There is a demo in it to show how to use the function.
If you get any bugs in the clean.hpp,please check the original tool.cpp or pull an issue or sent me an email at
cindyzhang.yono531@gmail.com  

 ***
## Citation
If you use our code or method in your work, please cite the following:  
`
@inproceedings{qiu2018deeplidar,
  title={DeepLiDAR: Deep Surface Normal Guided Depth Prediction for Outdoor Scene from Sparse LiDAR Data and Single Color Image},
  author={Qiu, Jiaxiong and Cui, Zhaopeng and Zhang, Yinda and Zhang, Xingdi and Liu, Shuaicheng and Zeng, Bing and Pollefeys, Marc},
  booktitle={Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition},
  year={2019}
}`  

## The suggest environment is g++ 4.1/linux16.04, opencv2.4.9.
