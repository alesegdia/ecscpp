
uniform sampler2D texture;

const float blurSizeH = 1.0 / 1200.0;
const float blurSizeV = 1.0 / 800.0;

void main()
{
	// lookup the pixel in the texture
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy/4);

	gl_FragColor = pixel;
	//gl_FragColor = gl_Color * vec4(pix); //pixel;
	//gl_FragColor = gl_Color * vec4(val, 1); //pixel;
}
