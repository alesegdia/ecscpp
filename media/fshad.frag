
uniform sampler2D texture;

const float blurSizeH = 1.0 / 2400.0;
const float blurSizeV = 1.0 / 1600.0;
const float scale = 1;
void main()
{
	// lookup the pixel in the texture
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy/scale);

	vec4 sum = vec4(0.0);
	for( int i = -5; i <= 5; i++ )
	for( int j = -5; j <= 5; j++ )
	{
		sum += texture2D(texture, vec2(gl_TexCoord[0].x + i * blurSizeH, gl_TexCoord[0].y + j * blurSizeV)/scale)/81.0;
	}
	gl_FragColor = lerp(pixel, vec4(sum.xyz,1), 0.5);

	//float pix = (pixel.r + pixel.g + pixel.b)/3;
	// multiply it by the color
	//gl_FragColor = gl_Color * vec4(pix); //pixel;
	//gl_FragColor = gl_Color * vec4(val, 1); //pixel;
}
