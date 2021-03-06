
DEFINES += M_ENABLE_OPENCV310

INCLUDEPATH  += $$PWD/include

LIBS += $$PWD/x86/mingw/bin/libopencv_world310.dll \
        $$PWD/x86/mingw/bin/opencv_ffmpeg310.dll

DISTFILES += $$PWD/etc/haarcascades/* \
             $$PWD/etc/lbpcascades/*
 
HEADERS += \ 
    $$PWD/include/opencv2/shape/emdL1.hpp \ 
    $$PWD/include/opencv2/shape/hist_cost.hpp \ 
    $$PWD/include/opencv2/shape/shape_distance.hpp \ 
    $$PWD/include/opencv2/shape/shape.hpp \ 
    $$PWD/include/opencv2/shape/shape_transformer.hpp \ 
    $$PWD/include/opencv2/core/hal/hal.hpp \ 
    $$PWD/include/opencv2/core/hal/interface.h \ 
    $$PWD/include/opencv2/core/hal/intrin_cpp.hpp \ 
    $$PWD/include/opencv2/core/hal/intrin.hpp \ 
    $$PWD/include/opencv2/core/hal/intrin_neon.hpp \ 
    $$PWD/include/opencv2/core/hal/intrin_sse.hpp \ 
    $$PWD/include/opencv2/core/affine.hpp \ 
    $$PWD/include/opencv2/core/base.hpp \ 
    $$PWD/include/opencv2/core/bufferpool.hpp \ 
    $$PWD/include/opencv2/core/core_c.h \ 
    $$PWD/include/opencv2/core/core.hpp \ 
    $$PWD/include/opencv2/core/cuda.hpp \ 
    $$PWD/include/opencv2/core/cuda.inl.hpp \ 
    $$PWD/include/opencv2/core/cuda_stream_accessor.hpp \ 
    $$PWD/include/opencv2/core/cuda_types.hpp \ 
    $$PWD/include/opencv2/core/cvdef.h \ 
    $$PWD/include/opencv2/core/cvstd.hpp \ 
    $$PWD/include/opencv2/core/cvstd.inl.hpp \ 
    $$PWD/include/opencv2/core/directx.hpp \ 
    $$PWD/include/opencv2/core/eigen.hpp \ 
    $$PWD/include/opencv2/core/fast_math.hpp \ 
    $$PWD/include/opencv2/core/ippasync.hpp \ 
    $$PWD/include/opencv2/core/mat.hpp \ 
    $$PWD/include/opencv2/core/mat.inl.hpp \ 
    $$PWD/include/opencv2/core/matx.hpp \ 
    $$PWD/include/opencv2/core/neon_utils.hpp \ 
    $$PWD/include/opencv2/core/ocl_genbase.hpp \ 
    $$PWD/include/opencv2/core/ocl.hpp \ 
    $$PWD/include/opencv2/core/opengl.hpp \ 
    $$PWD/include/opencv2/core/operations.hpp \ 
    $$PWD/include/opencv2/core/optim.hpp \ 
    $$PWD/include/opencv2/core/persistence.hpp \ 
    $$PWD/include/opencv2/core/private.cuda.hpp \ 
    $$PWD/include/opencv2/core/private.hpp \ 
    $$PWD/include/opencv2/core/ptr.inl.hpp \ 
    $$PWD/include/opencv2/core/saturate.hpp \ 
    $$PWD/include/opencv2/core/sse_utils.hpp \ 
    $$PWD/include/opencv2/core/traits.hpp \ 
    $$PWD/include/opencv2/core/types_c.h \ 
    $$PWD/include/opencv2/core/types.hpp \ 
    $$PWD/include/opencv2/core/utility.hpp \ 
    $$PWD/include/opencv2/core/va_intel.hpp \ 
    $$PWD/include/opencv2/core/version.hpp \ 
    $$PWD/include/opencv2/core/wimage.hpp \ 
    $$PWD/include/opencv2/superres/optical_flow.hpp \ 
    $$PWD/include/opencv2/objdetect/detection_based_tracker.hpp \ 
    $$PWD/include/opencv2/objdetect/objdetect_c.h \ 
    $$PWD/include/opencv2/objdetect/objdetect.hpp \ 
    $$PWD/include/opencv2/flann/all_indices.h \ 
    $$PWD/include/opencv2/flann/allocator.h \ 
    $$PWD/include/opencv2/flann/any.h \ 
    $$PWD/include/opencv2/flann/autotuned_index.h \ 
    $$PWD/include/opencv2/flann/composite_index.h \ 
    $$PWD/include/opencv2/flann/config.h \ 
    $$PWD/include/opencv2/flann/defines.h \ 
    $$PWD/include/opencv2/flann/dist.h \ 
    $$PWD/include/opencv2/flann/dummy.h \ 
    $$PWD/include/opencv2/flann/dynamic_bitset.h \ 
    $$PWD/include/opencv2/flann/flann_base.hpp \ 
    $$PWD/include/opencv2/flann/flann.hpp \ 
    $$PWD/include/opencv2/flann/general.h \ 
    $$PWD/include/opencv2/flann/ground_truth.h \ 
    $$PWD/include/opencv2/flann/hdf5.h \ 
    $$PWD/include/opencv2/flann/heap.h \ 
    $$PWD/include/opencv2/flann/hierarchical_clustering_index.h \ 
    $$PWD/include/opencv2/flann/index_testing.h \ 
    $$PWD/include/opencv2/flann/kdtree_index.h \ 
    $$PWD/include/opencv2/flann/kdtree_single_index.h \ 
    $$PWD/include/opencv2/flann/kmeans_index.h \ 
    $$PWD/include/opencv2/flann/linear_index.h \ 
    $$PWD/include/opencv2/flann/logger.h \ 
    $$PWD/include/opencv2/flann/lsh_index.h \ 
    $$PWD/include/opencv2/flann/lsh_table.h \ 
    $$PWD/include/opencv2/flann/matrix.h \ 
    $$PWD/include/opencv2/flann/miniflann.hpp \ 
    $$PWD/include/opencv2/flann/nn_index.h \ 
    $$PWD/include/opencv2/flann/object_factory.h \ 
    $$PWD/include/opencv2/flann/params.h \ 
    $$PWD/include/opencv2/flann/random.h \ 
    $$PWD/include/opencv2/flann/result_set.h \ 
    $$PWD/include/opencv2/flann/sampling.h \ 
    $$PWD/include/opencv2/flann/saving.h \ 
    $$PWD/include/opencv2/flann/simplex_downhill.h \ 
    $$PWD/include/opencv2/flann/timer.h \ 
    $$PWD/include/opencv2/imgcodecs/imgcodecs_c.h \ 
    $$PWD/include/opencv2/imgcodecs/imgcodecs.hpp \ 
    $$PWD/include/opencv2/imgcodecs/ios.h \ 
    $$PWD/include/opencv2/highgui/highgui_c.h \ 
    $$PWD/include/opencv2/highgui/highgui.hpp \ 
    $$PWD/include/opencv2/videoio/cap_ios.h \ 
    $$PWD/include/opencv2/videoio/videoio_c.h \ 
    $$PWD/include/opencv2/videoio/videoio.hpp \ 
    $$PWD/include/opencv2/ml/ml.hpp \ 
    $$PWD/include/opencv2/video/background_segm.hpp \ 
    $$PWD/include/opencv2/video/tracking_c.h \ 
    $$PWD/include/opencv2/video/tracking.hpp \ 
    $$PWD/include/opencv2/video/video.hpp \ 
    $$PWD/include/opencv2/stitching/detail/autocalib.hpp \ 
    $$PWD/include/opencv2/stitching/detail/blenders.hpp \ 
    $$PWD/include/opencv2/stitching/detail/camera.hpp \ 
    $$PWD/include/opencv2/stitching/detail/exposure_compensate.hpp \ 
    $$PWD/include/opencv2/stitching/detail/matchers.hpp \ 
    $$PWD/include/opencv2/stitching/detail/motion_estimators.hpp \ 
    $$PWD/include/opencv2/stitching/detail/seam_finders.hpp \ 
    $$PWD/include/opencv2/stitching/detail/timelapsers.hpp \ 
    $$PWD/include/opencv2/stitching/detail/util.hpp \ 
    $$PWD/include/opencv2/stitching/detail/util_inl.hpp \ 
    $$PWD/include/opencv2/stitching/detail/warpers.hpp \ 
    $$PWD/include/opencv2/stitching/detail/warpers_inl.hpp \ 
    $$PWD/include/opencv2/stitching/warpers.hpp \ 
    $$PWD/include/opencv2/videostab/deblurring.hpp \ 
    $$PWD/include/opencv2/videostab/fast_marching.hpp \ 
    $$PWD/include/opencv2/videostab/fast_marching_inl.hpp \ 
    $$PWD/include/opencv2/videostab/frame_source.hpp \ 
    $$PWD/include/opencv2/videostab/global_motion.hpp \ 
    $$PWD/include/opencv2/videostab/inpainting.hpp \ 
    $$PWD/include/opencv2/videostab/log.hpp \ 
    $$PWD/include/opencv2/videostab/motion_core.hpp \ 
    $$PWD/include/opencv2/videostab/motion_stabilizing.hpp \ 
    $$PWD/include/opencv2/videostab/optical_flow.hpp \ 
    $$PWD/include/opencv2/videostab/outlier_rejection.hpp \ 
    $$PWD/include/opencv2/videostab/ring_buffer.hpp \ 
    $$PWD/include/opencv2/videostab/stabilizer.hpp \ 
    $$PWD/include/opencv2/videostab/wobble_suppression.hpp \ 
    $$PWD/include/opencv2/features2d/features2d.hpp \ 
    $$PWD/include/opencv2/calib3d/calib3d_c.h \ 
    $$PWD/include/opencv2/calib3d/calib3d.hpp \ 
    $$PWD/include/opencv2/photo/cuda.hpp \ 
    $$PWD/include/opencv2/photo/photo_c.h \ 
    $$PWD/include/opencv2/photo/photo.hpp \ 
    $$PWD/include/opencv2/imgproc/detail/distortion_model.hpp \ 
    $$PWD/include/opencv2/imgproc/imgproc_c.h \ 
    $$PWD/include/opencv2/imgproc/imgproc.hpp \ 
    $$PWD/include/opencv2/imgproc/types_c.h \ 
    $$PWD/include/opencv2/calib3d.hpp \ 
    $$PWD/include/opencv2/core.hpp \ 
    $$PWD/include/opencv2/cvconfig.h \ 
    $$PWD/include/opencv2/features2d.hpp \ 
    $$PWD/include/opencv2/flann.hpp \ 
    $$PWD/include/opencv2/highgui.hpp \ 
    $$PWD/include/opencv2/imgcodecs.hpp \ 
    $$PWD/include/opencv2/imgproc.hpp \ 
    $$PWD/include/opencv2/ml.hpp \ 
    $$PWD/include/opencv2/objdetect.hpp \ 
    $$PWD/include/opencv2/opencv.hpp \ 
    $$PWD/include/opencv2/opencv_modules.hpp \ 
    $$PWD/include/opencv2/photo.hpp \ 
    $$PWD/include/opencv2/shape.hpp \ 
    $$PWD/include/opencv2/stitching.hpp \ 
    $$PWD/include/opencv2/superres.hpp \ 
    $$PWD/include/opencv2/video.hpp \ 
    $$PWD/include/opencv2/videoio.hpp \ 
    $$PWD/include/opencv2/videostab.hpp \ 
    $$PWD/include/opencv2/world.hpp \ 
    $$PWD/include/opencv/cvaux.h \ 
    $$PWD/include/opencv/cvaux.hpp \ 
    $$PWD/include/opencv/cv.h \ 
    $$PWD/include/opencv/cv.hpp \ 
    $$PWD/include/opencv/cvwimage.h \ 
    $$PWD/include/opencv/cxcore.h \ 
    $$PWD/include/opencv/cxcore.hpp \ 
    $$PWD/include/opencv/cxeigen.hpp \ 
    $$PWD/include/opencv/cxmisc.h \ 
    $$PWD/include/opencv/highgui.h \ 
    $$PWD/include/opencv/ml.h

 
