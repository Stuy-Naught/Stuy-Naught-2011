float target[3];
target[0] = 0.5;
target[1] = 0.5;
target[2] = 0;
switch(state % 4){
	case 1:
		target[1] = -0.5;
		break;
	case 2:
		target[0] = -0.5;
		break;
	case 3: 
		target[1] = 0.5;
		break;
	default:
		target[0] = 0.5;
}
if(mathSquare(target[0]-myState[0]) < 0.1 && mathSquare(target[1]-myState[1]) < 0.1){
	state++;
}
ZRSetPositionTarget(target);