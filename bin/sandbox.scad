union() {
  scale(v=[0.054, 0.054, 0.000]) {
    linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/S.dxf");}
  } // End scale
  translate(v=[10.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    scale(v=[0.054, 0.054, 0.000]) {
      linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/T.dxf");}
    } // End scale
  } // End rotate
  } // End translate
  translate(v=[20.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    scale(v=[0.054, 0.054, 0.000]) {
      linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/R.dxf");}
    } // End scale
  } // End rotate
  } // End translate
  translate(v=[30.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    scale(v=[0.054, 0.054, 0.000]) {
      linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/I.dxf");}
    } // End scale
  } // End rotate
  } // End translate
  translate(v=[40.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    scale(v=[0.054, 0.054, 0.000]) {
      linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/N.dxf");}
    } // End scale
  } // End rotate
  } // End translate
  translate(v=[50.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    scale(v=[0.054, 0.054, 0.000]) {
      linear_extrude(height=5.000, twist=0, $fn=100, convexity=10, center=true){import ("/home/avalero/workspace/OOML/data/dxf/G.dxf");}
    } // End scale
  } // End rotate
  } // End translate
} // End union
