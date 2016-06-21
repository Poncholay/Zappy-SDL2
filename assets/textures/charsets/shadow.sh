shopt -s globstar
for i in $(find -name image.png); do
    mv "$i" "./lol.png"
    convert "./lol.png" -alpha on -channel rgba -fill "rgba(0,0,0,0.4)" -opaque "rgba(0,0,0,255)" "$i"
    rm "./lol.png"
done


