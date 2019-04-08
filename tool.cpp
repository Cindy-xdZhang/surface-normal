Mat 
calplanenormal(Mat  &src){
	 float f =fcxcy[0];
	 float cx=fcxcy[1];
	 float cy=fcxcy[2];
     Mat normals = Mat::zeros(src.size(),CV_32FC3);
	 src.convertTo(src,CV_32FC1);
	 src*=1.0;
	 int cols =src.cols;
	 int rows =src.rows;
    //  int plane_points[WINDOWSIZE*WINDOWSIZE]={0};
	 int * plane_points = new int[WINDOWSIZE*WINDOWSIZE];
	 float * plane12 = new float[4];
	 for (int i=0;i< rows;i++)
				for (int j=0;j< cols;j++){
                    //for kitti and nyud test
					if(src.at<float>(i,j)==0.0)continue;
                    //for:nyud train
                    //  if(src.at<float>(i,j)<=4000.0)continue;   

					search_plane_neighbor(src,i,j,15.0,plane_points);
					CallFitPlane(src,plane_points,i,j,plane12);
					Vec3f d = Vec3f(plane12[0],plane12[1],plane12[2]);
					Vec3f n = normalize(d);
					normals.at<Vec3f>(i, j) = n;
			}
	 Mat res = Mat::zeros(src.size(),CV_32FC3);
     for (int i=0;i<rows;i++)
      for (int j=0;j<cols;j++){
        res.at<Vec3f>(i, j)[0] = -1.0 * normals.at<Vec3f>(i, j)[0];
        res.at<Vec3f>(i, j)[2] = -1.0 * normals.at<Vec3f>(i, j)[1];
        res.at<Vec3f>(i, j)[1] = -1.0 * normals.at<Vec3f>(i, j)[2];
     }

	 delete[] plane12;
	 delete[] plane_points;
	 normals.release();
     for (int i=0;i<rows;i++)
      for (int j=0;j<cols;j++){
		if(!(res.at<Vec3f>(i, j)[0]==0&&res.at<Vec3f>(i, j)[1]==0&&res.at<Vec3f>(i, j)[2]==0)){
			res.at<Vec3f>(i, j)[0] += 1.0 ;
			res.at<Vec3f>(i, j)[2] += 1.0 ;
			res.at<Vec3f>(i, j)[1] += 1.0;
		 }
      }
	 
     res =res * 127.5;
     res.convertTo(res, CV_8UC3);
     cvtColor(res, res, COLOR_BGR2RGB);
	 return res;
}
